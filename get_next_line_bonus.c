/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:23:41 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/16 17:39:44 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*string[4096];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 4096)
		return (NULL);
	if (!string[fd])
	{
		string[fd] = malloc(1);
		if (!string[fd])
			return (NULL);
		string[fd][0] = '\0';
	}
	string[fd] = ft_allocate(string[fd], fd);
	if (!string[fd])
		return (free_static(&string[fd], NULL));
	out = ft_next_line(string[fd]);
	if (!out)
		return (free_static(&string[fd], NULL));
	string[fd] = ft_remove_line(string[fd]);
	if (!string[fd])
		free_static(&string[fd], NULL);
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
