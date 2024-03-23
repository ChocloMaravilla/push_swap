/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:52:53 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/23 16:42:40 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	creation_node(t_stack **lista, t_stack *node, t_stack *first_node)
{
	t_stack	*temp;

	if (!first_node)
	{
		first_node = node;
		*lista = first_node;
	}
	else
	{
		temp = first_node;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	return (SUCCESS);
}

void	parse_stack(t_stack *node, int count, char **argv)
{
	node->index = count - 1;
	node->value = ft_atoi(argv[count]);
}

int	length_stack(t_stack **stacks)
{
	int		count;
	t_stack	*list;

	list = *stacks;
	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

void	free_elements_stack(t_stack **stacks)
{
	t_stack	*last;
	
	while ((*stacks) != NULL)
	{
		last = (*stacks)->next;
		free(*stacks);
		*stacks = last;
	}
}
