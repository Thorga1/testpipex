/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:35 by tordner           #+#    #+#             */
/*   Updated: 2024/12/02 17:53:15 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_get_word(const char *s, int start, int end)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	while (start < end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

static void	ft_free(char **new, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(new[i]);
		i++;
	}
	free(new);
}

static int	ft_set_start(char const *s, char c, int start)
{
	while (s[start] != c && s[start] != '\0')
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		start;

	i = 0;
	start = 0;
	new = (char **)malloc((sizeof(char *) * (ft_count_words(s, c) + 1)));
	if (s == NULL || new == NULL)
		return (0);
	while (i < ft_count_words(s, c))
	{
		if (start != ft_set_start(s, c, start))
		{
			new[i++] = ft_get_word(s, start, ft_set_start(s, c, start));
			if (new[i - 1] == NULL)
			{
				ft_free(new, i - 1);
				return (NULL);
			}
		}
		start = ft_set_start(s, c, start) + 1;
	}
	new[i] = NULL;
	return (new);
}
