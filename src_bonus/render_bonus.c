/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:51:08 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:15:55 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_nb_to_screen(t_game *data, int nb)
{
	char	*nb_temp;

	nb_temp = ft_itoa(nb);
	mlx_string_put(data->mlx, data->window, data->w_size.x - SPRITE_SIZE / 2,
		data->w_size.y - SPRITE_SIZE / 2, 0xFFFFFFFF, nb_temp);
	free(nb_temp);
}

void	draw_images(t_game *data, int x, int y)
{	
	t_tiletype	type;

	type = data->tilemap[x][y].type;
	if (type == WALL)
		mlx_put_image_to_window(data->mlx, data->window, data->w_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == EMPTY)
		mlx_put_image_to_window(data->mlx, data->window, data->f_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == PLAYER)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == EXIT)
		mlx_put_image_to_window(data->mlx, data->window,
			data->ex_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (type == HORIZONTAL || type == VERTICAL)
		mlx_put_image_to_window(data->mlx, data->window,
			data->en_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
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
