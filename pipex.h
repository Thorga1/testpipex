/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:44 by tordner           #+#    #+#             */
/*   Updated: 2024/12/04 15:03:28 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>

int		errors(int ac, char **av);
int		open_file(char *file, int flags, int mode);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		setup_files(char **av, int *infile, int *outfile);
void	close_files(int infile, int outfile);
char	*find_command(char **paths, char *cmd);
char	*get_path_env(char **envp);

#endif