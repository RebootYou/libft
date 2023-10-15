/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:43:52 by clegros           #+#    #+#             */
/*   Updated: 2023/10/14 20:04:15 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_free(char **tableau, size_t index)
{
	if (tableau[index] == NULL)
	{
		while (index > 0)
		{
			free(tableau[index]);
			index--;
		}
		free (tableau);
	}
	return ;
}

static char	**ft_alloc_tab(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	count++;
	return (ft_calloc(count, sizeof(char *)));
}

static void	ft_fill_tab(char **tableau, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str;

	i = 0;
	j = 0;
	str = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
		{
			tableau[str] = ft_substr(s, j, i - j);
			ft_check_free(tableau, str);
		}
		if (s[i])
			str++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tableau;

	if (s == NULL)
		return (NULL);
	tableau = ft_alloc_tab(s, c);
	if (tableau == NULL)
		return (NULL);
	ft_fill_tab(tableau, s, c);
	return (tableau);
}
