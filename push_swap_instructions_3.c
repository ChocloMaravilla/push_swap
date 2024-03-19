/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:43:44 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/06 18:57:54 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función rota hacia arriba todos los elementos de 
// ambas pilas, es decir, el último elemento
// de cada pila pasa a ser el primero. Se proporciona un 
// identificador de pila para mostrar mensajes de salida
// adecuados antes de realizar la rotación.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(&*stack_a, STACK_S);
	ra(&*stack_b, ERROR);
}
