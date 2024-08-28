/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:29:39 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/27 17:13:59 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_bigger_node(t_stack_node *stack)
{
	int				i;
	t_stack_node	*bigger_node;

	if (stack == NULL)
		return (NULL);
	i = INT_MIN;
	while (stack)
	{
		if (stack->nbr > i)
		{
			i = stack->nbr;
			bigger_node = stack;
		}
		stack = stack->next;
	}
	return (bigger_node);
}

t_stack_node	*find_the_smallest_node(t_stack_node *stack)
{
	long			i;
	t_stack_node	*the_smallest_node;

	if (stack == NULL)
		return (NULL);
	i = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < i)
		{
			i = stack->nbr;
			the_smallest_node = stack;
		}
		stack = stack->next;
	}
	return (the_smallest_node);
}

t_stack_node	*find_last_node(t_stack_node *top_node)
{
	if (NULL == top_node)
		return (NULL);
	while (top_node->next)
		top_node = top_node->next;
	return (top_node);
}

void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}
