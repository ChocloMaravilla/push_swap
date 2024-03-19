/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:00:19 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/19 21:52:50 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int is_Max_int(char **argv, int argc)
// {
// 	long	buffer;
// 	int		count;

// 	count = 1;
// 	while (count < argc)
// 	{
// 		buffer = ft_atoi(argv[count - 1]);
// 		if (buffer > 2147483647)
// 		{
// 			write(2, "Error\n", 6);
// 			return (ERROR);
// 		}
// 		count++;
// 	}
// 	return (EQUAL);
// }
int	count_bit_rows(int num_count)
{
	int	row_count;

	row_count = 0;
	while (num_count >> row_count)
		row_count++;
	return (row_count);
}

// Esta función implementa el algoritmo de ordenamiento 
// radix para ordenar una pila de enteros.
// Utiliza un enfoque especial para arreglos 
// pequeños (6 o menos elementos) y el algoritmo de
// ordenamiento radix convencional para arreglos más grandes.
//  
// Para arreglos pequeños, llama a la función algorithm_specialcase.
// Para arreglos más grandes, aplica el algoritmo de ordenamiento 
// radix, iterando sobre el número de bits
// necesarios para representar el mayor índice en la pila. 
// En cada iteración, separa los elementos de la
// pila A en grupos basados en el bit actual y los mueve a 
// la pila B o los regresa a la pila A según sea necesario.
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

// Esta función toma un arreglo de cadenas de caracteres
// que representan los números a ordenar.
// Crea dos pilas (A y B) y llena la pila A con los números 
// del arreglo. Luego, utiliza el algoritmo
// de ordenamiento radix para ordenar los números en la pila A. 
// Finalmente, libera la memoria
// asignada a la pila A.
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
		return (NULL);
	}
	else if (boolean == EQUAL)
		return (NULL);
	fill_index(first_node_a);
	fill_index(first_node_b);
	radix_algorithm(&first_node_a, &first_node_b, argc - 1, argc);
	// print_list(&first_node_a, "STACK_A");
	// print_list(&first_node_b, "STACK_B");
	free_elements_stack(&first_node_a);
	return (NULL);
}

int	main(int argc, char **argv )
{
	push_swap(argc, argv);

	return (0);
}



// //FUNCIONES PARA BORRAR SON DE TESTEO--------------->
void print_list(t_stack **list, char *name_list)
{
	t_stack *lists = *list;
	while (lists != NULL)
	{
		printf("\n%s: %i\n", name_list, lists->value);
		lists = lists->next;
	}
}