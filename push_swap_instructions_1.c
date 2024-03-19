/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:26:15 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:54 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función intercambia los dos primeros elementos de 
// una pila dada. Si la pila contiene menos de dos elementos,
// no se realiza ninguna operación. Si se proporciona un 
// identificador de pila, se muestra el mensaje correspondiente
// en la salida estándar antes de realizar el intercambio.
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

// Esta función llama a la función 'sa' para realizar un 
// intercambio entre los dos primeros elementos
// de la pila B. La función 'sa' se encarga de realizar la 
// operación de intercambio en la pila
// especificada. Esta función es específica para el caso 
// de la pila B.
void	sb(t_stack **stack_b)
{
	sa(stack_b, STACK_B);
}

// Esta función intercambia los dos primeros elementos de ambas 
// pilas, equivalente a ejecutar
// las operaciones 'sa' (swap A) y 'sb' (swap B) simultáneamente. 
// Se proporciona un identificador de pila
// para mostrar mensajes de salida adecuados antes de realizar 
// los intercambios.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, STACK_S);
	sa(stack_b, ERROR);
}

// Esta función toma el elemento superior de la pila B y 
// lo mueve a la pila A.
// Si la pila B no está vacía, se mueve el elemento superior 
// a la pila A y se actualizan
// los punteros de ambas pilas. Además, se imprime un mensaje 
// indicando la operación realizada.
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

// Esta función mueve el primer elemento de la pila A a la pila B. 
// Esencialmente, es equivalente
// a ejecutar la operación 'pa' (push A) con las pilas invertidas.
void	pb(t_stack **stack_b, t_stack **stack_a)
{
	pa(stack_b, stack_a, STACK_B);
}
