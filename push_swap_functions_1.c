/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:08:02 by ruben             #+#    #+#             */
/*   Updated: 2024/03/20 21:21:21 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función implementa casos especiales de algoritmos
// para tamaños específicos de pilas.
// Se utiliza para optimizar el rendimiento en 
// situaciones donde la cantidad de elementos en las pilas
// es pequeña y se puede aplicar una estrategia más eficiente.
void	algorithm_specialcase(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, STACK_A);
	}
	if (argc == 4)
		case3(stack_a, stack_b);
	else if (argc == 5)
		case4(stack_a, stack_b);
	else if (argc == 6)
		case5(stack_a, stack_b);
}

// Esta función implementa un caso especial de 
// algoritmo diseñado para ordenar
// tres elementos en la pila A de manera eficiente. 
// Se utilizan operaciones específicas
// para minimizar el número de movimientos necesarios.
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

// Esta función implementa un caso especial 
// de algoritmo diseñado para ordenar
// cuatro elementos en la pila A de manera eficiente. 
// Se utilizan operaciones específicas
// para minimizar el número de movimientos necesarios.
void	case4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = *stack_a;
	list_b = *stack_b;
	pb(&list_b, &list_a);
	case3(&list_a, &list_b);
	pa(&list_a, &list_b, STACK_A);
	if (list_a->value > list_a->next->value && \
		list_a->value < list_a->next->next->value)
		sa(&list_a, STACK_A);
	if (list_a->value > list_a->next->next->next->value)
		ra(&list_a, STACK_A);
	else if (list_a->value > list_a->next->next->value)
	{
		rra(&list_a, STACK_A);
		sa(&list_a, STACK_A);
		ra(&list_a, STACK_A);
		ra(&list_a, STACK_A);
	}
	*stack_a = list_a;
	*stack_b = list_b;
}

// Esta función implementa un caso especial de 
// algoritmo diseñado para ordenar
// cinco elementos en la pila A de manera eficiente. 
// Se utilizan operaciones específicas
// para minimizar el número de movimientos necesarios.
void	case5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = *stack_a;
	list_b = *stack_b;
	pb(&list_b, &list_a);
	case4(&list_a, &list_b);
	case5_2(&list_a, &list_b);
	*stack_a = list_a;
	*stack_b = list_b;
}

// Esta función implementa la segunda etapa de un 
// caso especial de algoritmo diseñado para ordenar
// cinco elementos en la pila A de manera eficiente. 
// Se utilizan operaciones específicas
// para minimizar el número de movimientos necesarios.
void	case5_2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = *stack_a;
	list_b = *stack_b;
	// pa(&list_a, &list_b, STACK_A);
	if (list_b->value > list_a->next->next->next->value)
	{
		pa(&list_a, &list_b, STACK_A);
		ra(&list_a, STACK_A);
	}
	else if (list_b->value > list_a->next->next->value)
	{
		rra(&list_a, STACK_A);
		pa(&list_a, &list_b, STACK_A);
		ra(&list_a, STACK_A);
		ra(&list_a, STACK_A);
	}
	case5_conditions(&list_a, &list_b);
	*stack_a = list_a;
	*stack_b = list_b;
}
