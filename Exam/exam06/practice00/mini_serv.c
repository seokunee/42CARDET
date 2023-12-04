#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_clients {
	int id;
	char msg[1024];
} t_clients;

t_clients clients[1024];
fd_set readfds, writefds, active; // fd_set은 파일 디스크립터 관리 데이터 구조. => 다중 입출력에 사용된다.
int fdMax = 0, idNext = 0;
char bufferRead[120000], bufferWrite[120000];

void ftError(char *str){
	if (str)
		write(2, str, strlen(str));
	else
		write(2, "Fatal error", strlen("Fatal error"));
	write(2, "\n", 1);
	exit(1);
}

void sendAll(int not){
	for (int i = 0; i <= fdMax; i++)
		if (FD_ISSET(i, &writefds) && i != not) // 주어진 fd가 설정되어있는지 확인함.
			send(i, bufferWrite, strlen(bufferWrite), 0);
}

int main(int ac, char** av){
	if (ac != 2)
		ftError("Wrong number of arguments");

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		ftError(NULL);

	FD_ZERO(&active);
	bzero(&clients, sizeof(clients)); // == memset(&clients, 0, sizeof(clients));
	fdMax = sockfd;
	FD_SET(sockfd, &active); // active에 sockfd를 추가함.
	
	struct sockaddr_in servaddr;
	socklen_t len;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1 === INADDR_LOOPBACK
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
		ftError(NULL);
	if (listen(sockfd, 10) < 0)
		ftError(NULL);

	while (1){
		readfds = writefds = active; // 지금 활동하고 있는 애들로 초기화? == 와이?
		if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0) // fdMax + 1 == 감시 범위
			continue;
		for (int fdI = 0; fdI <= fdMax; fdI++){
			if (FD_ISSET(fdI, &readfds) && fdI == sockfd){ // read에 있느지 확인하고 그게 sockfd랑 맞는지 확인 === 서버에 시그널 들어온 것임
				int connfd = accept(sockfd, (struct sockaddr*)&servaddr, &len);
				if (connfd < 0)
					continue;
				fdMax = connfd > fdMax ? connfd : fdMax;
				clients[connfd].id = idNext++;
				FD_SET(connfd, &active);
				sprintf(bufferWrite, "server: client %d just arrived\n", clients[connfd].id);
				sendAll(connfd);
				break;
			}
			if (FD_ISSET(fdI, &readfds) && fdI != sockfd){
				int res = recv(fdI, bufferRead, 65536, 0);
				if (res <= 0){ // 떠났을 경우
					sprintf(bufferWrite, "server: client %d just left\n", clients[fdI].id);
					sendAll(fdI);
					FD_CLR(fdI, &active);
					close(fdI);
					break;
				}
				else {
					for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++){
						clients[fdI].msg[j] = bufferRead[i];
						if (clients[fdI].msg[j] == '\n'){ // 마지막
							clients[fdI].msg[j] = '\0';
							sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
							sendAll(fdI);
							bzero(&clients[fdI].msg, strlen(clients[fdI].msg)); // 비워주고
							j = -1; // 0부터 다시 담아줘야하기 때문에  
						}
					}
					break;
				}
			}
		}
	}
}