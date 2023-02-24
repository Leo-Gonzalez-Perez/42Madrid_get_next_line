/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:12 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/02/18 15:02:24 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*take_line(char *rest, int there_is_line)
{
	char	*line_to_rtn;
	int		i;

	i = 0;
	line_to_rtn = NULL;
	line_to_rtn = (char *)malloc((there_is_line + 2) * sizeof(char));
	if (line_to_rtn == NULL)
		return (NULL);
	while (i < there_is_line + 1)
	{
		line_to_rtn[i] = rest[i];
		i++;
	}
	line_to_rtn[i] = '\0';
	return (line_to_rtn);
}

int	found_line(char *rest)
{
	int	i;

	i = 0;
	if (rest == NULL)
		return (-1);
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			return (i);
		else
			i++;
	}
	return (-1);
}

char	*hub(int fd, char *line, char *new_txt, char **rest)
{
	int		rtn_read;
	int		there_is_line;

	rtn_read = 0;
	while (1)
	{
		there_is_line = found_line(*rest);
		if (there_is_line >= 0)
		{
			line = take_line(*rest, there_is_line);
			*rest = set_rest(*rest, there_is_line);
			return (line);
		}
		rtn_read = read(fd, new_txt, BUFFER_SIZE);
		new_txt[rtn_read] = '\0';
		if (rtn_read == -1)
		{
			free(*rest);
			return (NULL);
		}
		if (rtn_read == 0)
			return (line = end(rest));
		*rest = rest_plus_new(*rest, new_txt);
	}
}

char	*init_str(char *str)
{
	int	i;

	i = 0;
	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i <= BUFFER_SIZE)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_txt;
	char		*rtn;	
	static char	*rest = NULL;

	line = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd < 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	if (rest == NULL)
		rest = init_str(rest);
	new_txt = init_str(rest);
	rtn = hub(fd, line, new_txt, &rest);
	free(new_txt);
	if (rest[0] == '\0' && rtn[0] == '\0')
	{
		free(rtn);
		free(rest);
		rest = NULL;
		return (NULL);
	}
	return (rtn);
}
