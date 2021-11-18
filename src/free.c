/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:06:22 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 16:04:33 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tilemap(t_game *data)
{
	int	x;

	x = 0;
	while (x < data->map_size.x)
	{
		free(data->tilemap[x]);
		x++;
	}
	free(data->tilemap);
}

int	end_game(t_game *data)
{
	free_tilemap(data);
	data->tilemap = NULL;
	exit(0);
}
