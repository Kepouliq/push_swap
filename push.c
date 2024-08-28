/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:15:12 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:05 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*head_node_to_push;

	if (*src == NULL)
		return ;
	head_node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	head_node_to_push->previous = NULL;
	if (*dest == NULL)
	{
		*dest = head_node_to_push;
		head_node_to_push->next = NULL;
	}
	else
	{
		head_node_to_push->next = *dest;
		head_node_to_push->next->previous = head_node_to_push;
		*dest = head_node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
