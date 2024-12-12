/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:38:13 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/12 15:39:37 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	string = ft_allocate(string, fd);
	out = ft_next_line(string);
	string = ft_remove_line(string);
	// printf("%s",out);
	return (out);
}

char	*ft_allocate(char *string, int fd)
{
	int		count;
	char	*aux_buffer;

	count = 1;
	aux_buffer = malloc(BUFFER_SIZE + 1);
	if (!aux_buffer)
		return (NULL);
	while ((!ft_strchar(string, '\n') && count > 0))
	{
		count = read(fd, aux_buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(aux_buffer);
			return (NULL);
		}
		aux_buffer[count] = '\0';
		string = ft_str_join(string, aux_buffer);
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

	// if (!string)
	// {
	// 	string = malloc(1);
	// 	if(!string)
	// 		return(NULL);
	// 	string[0] = '\0';
	// }
	i = 0;
	j = 0;
	string_joined = malloc(ft_str_len(string) + ft_str_len(string_to_join) + 1);
	if (!string_joined)
		return (NULL);
	while (string[j])
		string_joined[i++] = string[j++];
	i = 0;
	while (string_to_join[i])
		string_joined[j++] = string_to_join[i++];
	string_joined[j] = '\0';
	free(string);
	return (string_joined);
}

int	ft_str_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_next_line(char *string)
{
	int		i;
	char	*new_string;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	new_string = malloc(i + 2);
	 if (new_string== NULL)
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
	int i;
	int j;
	char *new_string;

	i = 0;
	j = 0;
	while (string[i] && string[i] != '\n')
		i++;
	new_string = malloc((ft_str_len(string) - i) + 2);
	if(!new_string)
		return (NULL);
	i++;
	if (!new_string)
		return (NULL);
	while (string[i])
		new_string[j++] = string[i++];
	new_string[j] = '\0';
	free(string);
	return (new_string);
}