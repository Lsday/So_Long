/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anims.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:17:19 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:20:43 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	anim_collectible(t_game *data, t_tile *tile)
{
	static int	frames = 0;

	frames++;
	if (frames <= 30)
		mlx_put_image_to_window(data->mlx, data->window,
			data->c1_img, tile->position.x, tile->position.y);
	else if (frames <= 60)
		mlx_put_image_to_window(data->mlx, data->window,
			data->c2_img, tile->position.x, tile->position.y);
	else if (frames <= 120)
	{		
		mlx_put_image_to_window(data->mlx, data->window, data->c2_img,
			tile->position.x, tile->position.y);
		frames = 0;
	}
}

void	anim(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == COLLECTIBLE)
				anim_collectible(data, &(data->tilemap[x][y]));
			x++;
		}
		y++;
	}	
}
