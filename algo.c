/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:37:08 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/27 17:12:22 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_stack(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	init_position_and_mediane(*a);
	init_position_and_mediane(*b);
}

static void	reverse_rotate_both_stack(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	init_position_and_mediane(*a);
	init_position_and_mediane(*b);
}

void	sort_node_in_other_stack(t_stack_node **stack, t_stack_node *top_node,
		char which_stack)
{
	while (*stack != top_node)
	{
		if (which_stack == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (which_stack == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_node_from_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = give_me_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both_stack(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_both_stack(a, b, cheapest);
	sort_node_in_other_stack(b, cheapest, 'b');
	sort_node_in_other_stack(a, cheapest->target, 'a');
	pa(a, b);
}

void	algo(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a);
	sort_three(a);
	while (*b)
	{
		algo_init(*a, *b);
		move_node_from_b_to_a(a, b);
	}
	init_position_and_mediane(*a);
	smallest = find_the_smallest_node(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
