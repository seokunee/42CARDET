/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/02 19:43:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

int	main(int ac, char **av)
{
	t_data data;
	make_linked_list(ac, av, &data);
	return (0);
}

void	make_linked_list(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	data->list = ft_pw_lstnew(ft_atoi(av[1]));
	while (i <= ac)
	{
		
		i++;
	}
}

t_pw_list	*ft_pw_lstnew(int	value)
{
	t_pw_list	*new;

	new = (t_pw_list *)malloc(sizeof(t_pw_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}