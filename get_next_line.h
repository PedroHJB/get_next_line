/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:22:03 by pede-jes          #+#    #+#             */
/*   Updated: 2024/12/16 17:23:25 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_allocate(char *string, int fd);
char	*ft_strchar(char *string, int c);
char	*ft_str_join(char *string, char *string_to_join);
int		ft_str_len(char *string);
char	*ft_next_line(char *string);
char	*ft_remove_line(char *string);
void	*free_static(char **first_str, char **second_str);

#endif