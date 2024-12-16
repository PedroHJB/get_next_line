/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:38:36 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/16 17:36:07 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_allocate(char *string, int fd)
{
	int		count;
	char	*aux_buffer;
	char	*temp;

	count = 1;
	aux_buffer = malloc(BUFFER_SIZE + 1);
	if (!aux_buffer)
		return (free_static(&string, NULL));
	while ((!ft_strchar(string, '\n') && count > 0))
	{
		count = read(fd, aux_buffer, BUFFER_SIZE);
		if (count < 0)
			return (free_static(&aux_buffer, &string));
		aux_buffer[count] = '\0';
		temp = ft_str_join(string, aux_buffer);
		if (!temp)
			return (free_static(&aux_buffer, &string));
		string = temp;
		if (count == 0 && string[0] == '\0')
			return (free_static(&aux_buffer, &string));
	}
	free(aux_buffer);
	return (string);
}

char	*ft_strchar(char *string, int c)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	return (0);
}

char	*ft_str_join(char *string, char *string_to_join)
{
	char	*string_joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string_joined = malloc(ft_str_len(string) + ft_str_len(string_to_join) + 1);
	if (!string_joined)
	{
		free(string);
		return (NULL);
	}
	while (string[j])
		string_joined[i++] = string[j++];
	j = 0;
	while (string_to_join[j])
		string_joined[i++] = string_to_join[j++];
	string_joined[i] = '\0';
	free(string);
	return (string_joined);
}

char	*ft_next_line(char *string)
{
	int		i;
	char	*new_string;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	new_string = malloc(i + 2);
	if (!new_string)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		new_string[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		new_string[i] = '\n';
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_remove_line(char *string)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	j = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_string = malloc((ft_str_len(string) - i) + 1);
	if (!new_string)
	{
		free(string);
		return (NULL);
	}
	i++;
	while (string[i])
		new_string[j++] = string[i++];
	new_string[j] = '\0';
	free(string);
	return (new_string);
}
