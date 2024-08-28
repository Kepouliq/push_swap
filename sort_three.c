/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:21 by kepouliq          #+#    #+#             */
/*   Updated: 2024/08/27 14:30:58 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*bigger_node;

	bigger_node = find_bigger_node(*a);
	if (*a == bigger_node)
		ra(a);
	else if ((*a)->next == bigger_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
