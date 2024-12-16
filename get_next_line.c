/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:23:41 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/16 15:23:44 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_static(char **first_str, char **second_str)
{
	if (first_str && *first_str)
		free(*first_str);
	if (second_str && *second_str)
		free(*second_str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*string;

	if (!string)
	{
		string = malloc(1);
		if (!string)
			return (NULL);
		string[0] = '\0';
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	string = ft_allocate(string, fd);
	if (!string)
		return (free_static(&string, NULL));
	out = ft_next_line(string);
	string = ft_remove_line(string);
	return (out);
}

int	ft_str_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
