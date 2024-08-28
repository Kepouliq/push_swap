/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:04:32 by kepouliq          #+#    #+#             */
/*   Updated: 2024/07/27 02:17:57 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		signe;
	int		i;

	num = 0;
	signe = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * signe);
}

void	init_stack(t_stack_node **a, char **tab, bool two_ac)
{
	long	nbr;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (check_correct_nbr(tab[i]))
			error_and_free(a, tab, two_ac);
		nbr = ft_atol(tab[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_and_free(a, tab, two_ac);
		if (check_double(*a, nbr))
			error_and_free(a, tab, two_ac);
		add_node(a, (int)nbr);
		i++;
	}
	if (two_ac)
		free_tab(tab);
	return ;
}
