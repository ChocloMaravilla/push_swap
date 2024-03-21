/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:26:15 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/21 17:39:04 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa( t_stack **first_node, int num_stack)
{
	t_stack	*current;
	t_stack	*next;

	(void)current;
	(void)next;
	if (length_stack(first_node) <= 1)
	{
		printf("----->%d\n", length_stack(first_node));
	}
	else
	{
		if (num_stack == 1)
			write(1, "sa\n", 3);
		else if (num_stack == 2)
			write(1, "sb\n", 3);
		else if (num_stack == 3)
			write(1, "ss\n", 3);
		current = *first_node;
		next = (*first_node)->next;
		current->next = next->next;
		next->next = (*first_node);
		*first_node = next;
	}
}

void	sb(t_stack **stack_b)
{
	sa(stack_b, STACK_B);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, STACK_S);
	sa(stack_b, ERROR);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int num_stack)
{
	t_stack	*temp;

	if (stack_b)
	{
		if (num_stack == 1)
			write(1, "pa\n", 3);
		else if (num_stack == 2)
			write(1, "pb\n", 3);
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	pa(stack_b, stack_a, STACK_B);
}
