/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:52:53 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/13 21:23:52 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  Esta función crea un nuevo nodo con la 
// información proporcionada y lo añade al final
//  de la lista enlazada especificada. Si la lista 
// está vacía, el nuevo nodo se convierte
//  en el primer nodo de la lista.
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

// Esta función toma un nodo de tipo t_stack, un contador y 
// un arreglo de cadenas de caracteres como entrada.
// Asigna el índice al nodo de la pila y convierte el valor 
// de la cadena en un número entero largo usando ft_atoi_long
// de la librería especificada. El valor convertido se asigna al nodo.
void	parse_stack(t_stack *node, int count, char **argv)
{
	node->index = count - 1;
	node->value = ft_atoi(argv[count]);
}

// Esta función calcula la longitud de una pila enlazada dada, 
// contando el número de nodos que contiene.
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

//  Esta función libera la memoria ocupada por los 
// elementos de una pila enlazada,
//  comenzando desde el primer nodo hasta el último. 
// Luego, asigna NULL al puntero
//  que apunta a la pila, indicando que la pila está vacía.
void	free_elements_stack(t_stack **stacks)
{
	int		count;
	t_stack	*last;

	count = 0;
	while ((*stacks) != NULL)
	{
		last = (*stacks)->next;
		free(*stacks);
		*stacks = last;
	}
}

// Esta función aplica condiciones adicionales para 
// el caso especial de cinco elementos en la pila A,
// con el fin de ordenar eficientemente los elementos 
// restantes después de aplicar el caso base.
void	case5_conditions(t_stack **list_a, t_stack **list_b)
{
	if ((*list_a)->value > (*list_a)->next->next->next->next->value)
		ra(list_a, STACK_A);
	if ((*list_a)->value > (*list_a)->next->next->value)
	{
		ra(list_a, STACK_A);
		pb(list_b, list_a);
		rra(list_a, STACK_A);
		sa(list_a, STACK_A);
		if ((*list_a)->next->value > (*list_a)->next->next->value)
		{
			ra(list_a, STACK_A);
			sa(list_a, STACK_A);
			rra(list_a, STACK_A);
		}
		pa(list_a, list_b, STACK_A);
	}
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a, STACK_A);
}
