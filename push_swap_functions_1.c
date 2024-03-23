/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:08:02 by ruben             #+#    #+#             */
/*   Updated: 2024/03/23 20:08:14 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_specialcase(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, STACK_A);
	}
	if (argc == 4)
		case3(stack_a, stack_b);
	else if (argc == 5 || argc == 6)
		case5(&(*stack_a), &(*stack_b), argc);
}

void	case3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		count;

	count = 0;
	list_a = *stack_a;
	list_b = *stack_b;
	while (count < 1)
	{
		if (list_a->value > list_a->next->next->value)
			ra(&list_a, STACK_A);
		if (list_a->next->value > list_a->next->next->value)
		{
			ra(&list_a, STACK_A);
			sa(&list_a, STACK_A);
			rra(&list_a, STACK_A);
		}
		if (list_a->value > list_a->next->next->value)
			ra(&list_a, STACK_A);
		if (list_a->value > list_a->next->value && \
		list_a->value < list_a->next->next->value)
			sa(&list_a, STACK_A);
		count++;
	}
	*stack_a = list_a;
}

void	case5(t_stack **list_a, t_stack **list_b, int argc)
{
	int	count;

	count = 1;
	while (count < argc)
	{
		if ((*list_a)->index == 0 || (*list_a)->index == 1)
			pb(list_b, list_a);
		else
			ra(list_a, STACK_A);
		count++;
	}
	if ((*list_b)->index < (*list_b)->next->index)
		sb (list_b);
	if (argc == 6)
		case3(&(*list_a), &(*list_b));
	else if (argc == 5)
	{
		if ((*list_a)->index > (*list_a)->next->index)
			sa (&(*list_a), STACK_A);
	}
	while ((*list_b) != NULL)
		pa (&(*list_a), &(*list_b), STACK_A);
}
