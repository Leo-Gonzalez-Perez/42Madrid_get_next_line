/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:51 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/02/16 18:34:19 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
char	*end(char **rest);
char	*rest_plus_new(char *rest, char *new_txt);
char	*set_rest(char *rest, int there_is_line);
char	*take_line(char *rest, int there_is_line);
int		found_line(char *rest);
char	*hub(int fd, char *line, char *new_txt, char **rest);
char	*init_str(char *str);
char	*get_next_line(int fd);

#endif
