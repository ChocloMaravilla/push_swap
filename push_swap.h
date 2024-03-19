/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:13:57 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/15 14:45:28 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define ERROR -1
# define EQUAL 2
# define STACK_A 1
# define STACK_B 2
# define STACK_S 3

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				value;
	int				index;
	struct t_stack	*next;
}	t_stack;
int		ft_isnum(int c);
int		its_sorted(t_stack **lista);
int		ft_isdupli(int argc, char **argv);
void	fill_index(t_stack *list);
int		ft_atoi(const char *str);
int		fill_lista(int argc, char **argv, t_stack **lista);
int		creation_node(t_stack **lista, t_stack *node, t_stack *first_node);
void	parse_stack(t_stack *node, int count, char **argv);
void	sa(t_stack **first_node, int num_stack);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b, int num_stack);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rra(t_stack **stacks, int num_stack);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stacks, int num_stack);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	radix_algorithm(t_stack **stack_a, \
t_stack **stack_b, int count, int argc);
void	algorithm_specialcase(t_stack **stack_a, t_stack **stack_b, int argc);
void	case3(t_stack **stack_a, t_stack **stack_b);
void	case4(t_stack **stack_b, t_stack **stack_a);
void	case5(t_stack **stack_b, t_stack **stack_a);
void	case5_2(t_stack **stack_a, t_stack **stack_b);
int		length_stack(t_stack **stacks);
void	free_elements_stack(t_stack **stacks);
void	positive_or_negative(const char *str, int *a, int *sign);
void	case5_conditions(t_stack **list_a, t_stack **list_b);
int		is_char(int count, char **argv);
#endif