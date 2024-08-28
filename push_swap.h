/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:26:44 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/27 16:22:15 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					position;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}						t_stack_node;

// checks argc :

int						check_correct_nbr(char *args);
int						check_double(t_stack_node *a, int nbr);

// split :

char					**ft_split(char *str, char sep);

// initialisation de la stack :

void					init_stack(t_stack_node **a, char **tab, bool two_arg);
void					add_node(t_stack_node **a, int nbr);

// stack utils :

bool					is_stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
t_stack_node			*give_me_cheapest(t_stack_node *stack);

// node utils :

t_stack_node			*find_last_node(t_stack_node *top_node);
t_stack_node			*find_bigger_node(t_stack_node *stack);
t_stack_node			*find_the_smallest_node(t_stack_node *stack);

// algorithme_init :

void					init_position_and_mediane(t_stack_node *stack);
void					algo_init(t_stack_node *a, t_stack_node *b);

// algo :

void					algo(t_stack_node **a, t_stack_node **b);

// swap :

void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);

// rotate :

void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);

// reverse rotate :

void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// push :

void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);

// sort three :

void					sort_three(t_stack_node **stack);

// free :

int						error_and_free(t_stack_node **a, char **tab,
							bool two_ac);
void					free_tab(char **tab);
void					free_stack(t_stack_node **stack);

// utils :

int						ft_isdigit(int c);

#endif