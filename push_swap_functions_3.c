/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:29 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/21 18:39:31 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack *list)
{
	t_stack	*cursor;
	t_stack	*first;
	int		count_index;

	first = list;
	while (list)
	{
		cursor = first;
		count_index = 0;
		while (cursor)
		{
			if (cursor->value < list->value)
				count_index++;
			cursor = cursor->next;
		}
		list->index = count_index;
		list = list->next;
	}
}

int	fill_lista(int argc, char **argv, t_stack **lista)
{
	int		count;
	t_stack	*node;

	count = 1;
	while (count < argc)
	{
		if (is_char(count, argv) == ERROR)
			return (ERROR);
		node = malloc(sizeof(t_stack));
		if (!node)
			return (ERROR);
		if (ft_isdupli(argc, argv) == ERROR)
			return (ERROR);
		if (creation_node(lista, node, *lista) == ERROR)
			return (ERROR);
		parse_stack(node, count, argv);
		count++;
	}
	if (its_sorted(lista) == EQUAL)
		return (EQUAL);
	return (SUCCESS);
}

int	its_sorted(t_stack **lista)
{
	t_stack	*next;
	t_stack	*current;
	int		its_bigger;

	current = *lista;
	its_bigger = 0;
	while (*lista != NULL && its_bigger != 1)
	{
		if (current->next != NULL && its_bigger == 0)
		{
			next = current->next;
			if (its_bigger == 0)
			{
				if (current->value < next->value)
					current = current->next;
				else if (current->value > next->value)
					its_bigger = 1;
			}
		}
		else if (current->next == NULL)
			return (EQUAL);
	}
	return (its_bigger);
}

int	is_char(int count, char **argv)
{
	int	i;

	i = 0;
	if (argv[count][i] == '\0')
		return (ERROR);
	while (argv[count][i])
	{
		if (counter_strings(argv[count]) == (ERROR))
			return (ERROR);
		if (argv[count][i] == '-' && (argv[count][i + 1] == '0'))
			i++;
		else if (argv[count][i] == '+' && (argv[count][i + 1] == '0'))
			i++;
		if (argv[count][i] && argv[count][i + 1] == '-')
			return (ERROR);
		else if (argv[count][i] && argv[count][i + 1] == '+')
			return (ERROR);
		if (argv[count][i] == '-' || argv[count][i] == '+')
			i++;
		if (ft_isnum(argv[count][i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}

int	counter_strings(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((count) == 11)
			return (ERROR);
		count++;
	}
	return (SUCCESS);
}
