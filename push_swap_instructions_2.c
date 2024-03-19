/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:40:09 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/19 18:46:33 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacks, int num_stack)
{
	t_stack	*cont;
	t_stack	*final;

	if (num_stack == 1)
		write(1, "rra\n", 4);
	else if (num_stack == 2)
		write(1, "rrb\n", 4);
	else if (num_stack == 3)
		write(1, "rrr\n", 4);
	cont = *stacks;
	while (cont->next != NULL)
	{
		final = cont;
		cont = cont->next;
	}
	cont->next = *stacks;
	if (final != NULL)
		final->next = NULL;
	*stacks = cont;
}

void	rrb(t_stack **stack_b)
{
	rra(&*stack_b, STACK_B);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(&*stack_a, STACK_S);
	rra(&*stack_b, ERROR);
}

void	ra(t_stack **stacks, int num_stack)
{
	t_stack	*first;
	t_stack	*final;

	if (num_stack == 1)
		write(1, "ra\n", 3);
	else if (num_stack == 2)
		write(1, "rb\n", 3);
	else if (num_stack == 3)
		write(1, "rr\n", 3);
	first = *stacks;
	final = *stacks;
	while (final->next != NULL)
	{
		final = final->next;
	}
	final->next = first;
	*stacks = first->next;
	first->next = NULL;
}

void	rb(t_stack **stack_b)
{
	ra(&*stack_b, STACK_B);
}
