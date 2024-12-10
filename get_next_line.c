/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:38:13 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/10 17:50:18 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *string;
	
	if(BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	string = ft_new_line(string, fd);
}

char *ft_new_line(char *string,int fd)
{
	int count; 
	char *aux_buffer;

	count = 1;
	aux_buffer = malloc(BUFFER_SIZE +1);
	while((!ft_strchar(string,'\n')&& count > 0))
	{
		if(count < 0)
		{
			free(aux_buffer);
			return (NULL);
		}
		string = read(fd,aux_buffer,BUFFER_SIZE);
		string[count] = '\0';
	}
}

char *ft_strchar(char *string, int c)
{
	size_t i;

	i = 0;
	while (string[i])
	{
		if(string[i]== c)
			return (&string[i]);
		i++;
	}
	
	return (0);
}