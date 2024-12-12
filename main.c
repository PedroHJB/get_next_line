/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:44:12 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/12 15:11:49 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char *s;
	int i;
	int fd;

	fd = open("teste.txt", O_RDONLY);
	i = 1;
	while (i < 100)
	{
		s = get_next_line(fd);
		printf("line [%02d]: %s", i, s);
		free(s);
		i++;
	}
	close(fd);
	return (0);
}