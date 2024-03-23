/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:00:19 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/23 18:02:29 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bit_rows(int num_count)
{
	int	row_count;

	row_count = 0;
	while (num_count >> row_count)
		row_count++;
	return (row_count);
}

void	radix_algorithm(t_stack **stack_a, t_stack **stack_b,
int count, int argc)
{
	int	n;
	int	row;

	row = 0;
	if (argc <= 6 && argc > 1)
		algorithm_specialcase(stack_a, stack_b, argc);
	else
	{
		while (row < count_bit_rows(count - 1))
		{
			n = 0;
			while (n++ < count)
			{
				if ((*stack_a)->index & (1 << row))
					ra(stack_a, STACK_A);
				else
					pb(stack_b, stack_a);
			}
			while (*stack_b)
				pa(stack_a, stack_b, STACK_A);
			row++;
		}
	}
}

void	*push_swap(int argc, char *argv[])
{
	t_stack	*first_node_a;
	t_stack	*first_node_b;
	int		boolean;

	first_node_a = NULL;
	first_node_b = NULL;
	if (!argv || argc < 2)
		return (NULL);
	boolean = fill_lista(argc, argv, &first_node_a);
	if (boolean == ERROR)
	{
		write(2, "Error\n", 6);
		// free_elements_stack(&first_node_a);
		// return (NULL);
		exit(0);
	}
	else if (boolean == EQUAL)
	{
		// free_elements_stack(&first_node_a);
		// return (0);
		exit(0);
	}
	fill_index(first_node_a);
	fill_index(first_node_b);
	radix_algorithm(&first_node_a, &first_node_b, argc - 1, argc);
	// free_elements_stack(&first_node_a);
	// return (NULL);
	exit(0);
}

int	main(int argc, char **argv )
{
	push_swap(argc, argv);
	return (0);
}

void print_list(t_stack **list, char *name_list)
{
	t_stack *lists = *list;
	while (lists != NULL)
	{
		printf("\n%s(%i): %i\n", name_list, lists->index,lists->value);
		lists = lists->next;
	}
}
