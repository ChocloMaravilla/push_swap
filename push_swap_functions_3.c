/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:29 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/15 17:47:39 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función asigna índices a los nodos de una 
// pila enlazada, donde el índice de un nodo
// representa la cantidad de nodos con valores menores que 
// el valor del nodo actual en la pila.
// Esto se hace recorriendo la lista y contando 
// los nodos con valores menores.
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

// Esta función crea nodos de tipo t_stack y 
// los añade a una lista enlazada, asignando
// valores desde un arreglo de cadenas de caracteres. 
// Para cada argumento en el arreglo argv,
// se crea un nuevo nodo, se comprueba si hay duplicados 
// utilizando ft_isdupli, y se añade
// el nodo a la lista utilizando la función creation_node. 
// Finalmente, se llama a parse_stack
// para asignar índices y valores a cada nodo.
int	fill_lista(int argc, char **argv, t_stack **lista)
{
	int		count;
	t_stack	*node;

	count = 1;
	while (count < argc)
	{
		if(is_char(count, argv) == ERROR)
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

// Esta función comprueba si una lista enlazada
// de tipo t_stack está ordenada de forma
// ascendente según los valores de los nodos.
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
int is_char(int count, char **argv)
{
	int i;

	i = 0;
	if(argv[count][i] == '\0')
		return (ERROR);
	// if(ft_atoi(argv[count]) > 2147483646)
	// 	return (ERROR);
	while (argv[count][i])
	{
		// if((argv[count][i] == '-') || (argv[count][i] == '+'))
		// 	i++;
		if(argv[count][i] == '-' && (argv[count][i + 1] == '0'))
			i++;
		if(!ft_isnum(argv[count][i]))
			return (ERROR);
		i++;
	}
	return 0;
}