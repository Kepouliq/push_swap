/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:06:46 by kepouliq          #+#    #+#             */
/*   Updated: 2024/07/26 16:38:07 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep
			&& (str[i + 1] == sep
				|| str[i + 1] == '\0'))
		{
			count += 1;
		}
		i++;
	}
	return (count);
}

static char	*get_next_word(char *str, char sep)
{
	int			i;
	static int	j = 0;
	int			len;
	char		*next_str;

	i = 0;
	len = 0;
	while (str[j] == sep)
		++j;
	while ((str[j + len] != sep) && str[j + len])
		++len;
	next_str = malloc(sizeof(char) * (len + 1));
	if (NULL == next_str)
		return (NULL);
	while ((str[j] != sep) && str[j])
		next_str[i++] = str[j++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		nb_word;
	char	**tab;
	int		i;

	i = 0;
	nb_word = ft_count_word(str, sep);
	if (!nb_word)
		exit(1);
	tab = malloc(sizeof(char *) * (nb_word + 2));
	if (NULL == tab)
		return (NULL);
	while (nb_word > 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char));
			if (NULL == tab[i])
				return (NULL);
			tab[i++][0] = '\0';
		}
		tab[i++] = get_next_word(str, sep);
		nb_word--;
	}
	tab[i] = NULL;
	return (tab);
}
