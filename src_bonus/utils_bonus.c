/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:47:30 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:15:53 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_char_valid(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n'
		|| c == 'V' || c == 'H')
		return (1);
	else
		return (0);
}

int	is_map_chars_valid(int fd)
{	
	int		r;
	char	buffer[1];
	int		buffer_size;

	buffer_size = 1;
	r = 1;
	while (r)
	{
		r = read(fd, buffer, buffer_size);
		if (!is_char_valid(*buffer))
			return (0);
	}
	close(fd);
	return (1);
}
