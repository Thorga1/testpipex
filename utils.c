/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:59 by tordner           #+#    #+#             */
/*   Updated: 2024/12/04 14:43:50 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	close_files(int infile, int outfile)
{
	close(infile);
	close(outfile);
}

int	setup_files(char **av, int *infile, int *outfile)
{
	*infile = open_file(av[1], O_RDONLY, 0);
	if (*infile == -1)
		return (1);
	*outfile = open_file(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile == -1)
	{
		close(*infile);
		return (1);
	}
	return (0);
}
