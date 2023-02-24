/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:18:12 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/02/16 19:18:37 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*end(char **rest)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*rest);
	temp = (char *)malloc((1 + len) * sizeof(char));
	while (i < len)
	{
		temp[i] = (*rest)[i];
		i++;
	}
	temp[len] = '\0';
	(*rest)[0] = '\0';
	return (temp);
}

char	*rest_plus_new(char *rest, char *new_txt)
{
	int		len[3];
	char	*rtn;

	len[0] = ft_strlen(rest);
	len[1] = ft_strlen(new_txt);
	len[2] = len[0] + len[1];
	rtn = malloc(sizeof(char) * (len[2] + 1));
	if (rtn == NULL)
		return (NULL);
	rtn[len[2]] = '\0';
	while (len[1] > 0)
	{
		len[1]--;
		len[2]--;
		rtn[len[2]] = new_txt[len[1]];
	}
	while (len[0] > 0)
	{
		len[0]--;
		len[2]--;
		rtn[len[0]] = rest[len[0]];
	}
	free(rest);
	return (rtn);
}

char	*set_rest(char *rest, int there_is_line)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	temp = NULL;
	i = ft_strlen(rest);
	temp = (char *)malloc((i - there_is_line) * sizeof(char));
	if (temp == NULL)
	{
		free (rest);
		return (NULL);
	}
	temp[i - there_is_line - 1] = '\0';
	while (there_is_line < i - 1)
	{
		temp[j] = rest[there_is_line + 1];
		j++;
		there_is_line++;
	}
	free(rest);
	return (temp);
}
