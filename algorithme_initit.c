/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_initit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:34:09 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/28 11:50:08 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_node;
	t_stack_node	*target;
	long			smallest_bigger;

	while (b)
	{
		smallest_bigger = LONG_MAX;
		a_node = a;
		while (a_node)
		{
			if (a_node->nbr > b->nbr && a_node->nbr < smallest_bigger)
			{
				smallest_bigger = a_node->nbr;
				target = a_node;
			}
			a_node = a_node->next;
		}
		if (smallest_bigger == LONG_MAX)
			b->target = find_the_smallest_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_position_and_mediane(t_stack_node *stack)
{
	int	i;
	int	mediane;

	i = 0;
	if (stack == NULL)
		return ;
	mediane = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= mediane)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	init_cost(t_stack_node *a, t_stack_node *b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(a);
	stack_b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->position;
		if (!(b->above_median))
			b->push_cost = stack_b_len - (b->position);
		if (b->target->above_median)
			b->push_cost += b->target->position;
		else
			b->push_cost += stack_a_len - (b->target->position);
		b = b->next;
	}
}

static void	init_cheapest(t_stack_node *b)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	if (b == NULL)
		return ;
	cheapest = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest)
		{
			cheapest = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	algo_init(t_stack_node *a, t_stack_node *b)
{
	init_position_and_mediane(a);
	init_position_and_mediane(b);
	init_target(a, b);
	init_cost(a, b);
	init_cheapest(b);
}
