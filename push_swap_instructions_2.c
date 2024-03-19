/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:40:09 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:03 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función rota hacia arriba todos los 
// elementos de la pila, es decir, el último elemento
// pasa a ser el primero. Se proporciona un identificador
// de pila para mostrar mensajes de salida
// adecuados antes de realizar la rotación.
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

// Esta función llama a la función 'rra' para realizar 
// una rotación hacia la derecha en la pila B.
// La función 'rra' se encarga de realizar la rotación 
// hacia la derecha en la pila especificada.
// Esta función es específica para el caso de la pila B.
void	rrb(t_stack **stack_b)
{
	rra(&*stack_b, STACK_B);
}

// Esta función realiza una rotación hacia la izquierda 
// en la pila especificada.
// Se toma el primer nodo de la pila y se mueve al final, 
// manteniendo el orden relativo
// de los demás nodos. Se imprime un mensaje dependiendo 
// del tipo de pila y la operación realizada.
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(&*stack_a, STACK_S);
	rra(&*stack_b, ERROR);
}

// Esta función rota hacia arriba todos los elementos de ambas 
// pilas, es decir, el último elemento
// de cada pila pasa a ser el primero. Se proporciona un identificador 
// de pila para mostrar mensajes de salida
// adecuados antes de realizar la rotación.
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

// Esta función rota hacia arriba todos los elementos de la pila B, 
// es decir, el último elemento
// pasa a ser el primero en la pila B. Se proporciona un identificador 
// de pila para mostrar mensajes de salida
// adecuados antes de realizar la rotación.
void	rb(t_stack **stack_b)
{
	ra(&*stack_b, STACK_B);
}
