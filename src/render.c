/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:51:08 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 15:07:44 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_images(t_game *data, int x, int y)
{	
	t_tiletype	type;

	type = data->tilemap[x][y].type;
	if (type == WALL)
		mlx_put_image_to_window(data->mlx, data->window, data->wall_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == EMPTY)
		mlx_put_image_to_window(data->mlx, data->window, data->floor_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == PLAYER)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx, data->window, data->collectible_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == EXIT)
		mlx_put_image_to_window(data->mlx, data->window,
			data->exit_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	render(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			draw_images(data, x, y);
			x++;
		}
		y++;
	}
}
