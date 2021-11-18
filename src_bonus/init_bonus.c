/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:54:07 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 14:53:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == PLAYER)
			{
				data->player.tile = &data->tilemap[x][y];
			}
			x++;
		}
		y++;
	}
}

void	init_collectible(t_game *data)
{
	int	x;
	int	y;

	data->start_collects_count = 0;
	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == COLLECTIBLE)
			{
				data->start_collects_count++;
			}
			x++;
		}
		y++;
	}
	data->collects_count = data->start_collects_count;
}

void	init_imgs(t_game *data)
{
	data->w_img = mlx_xpm_file_to_image(data->mlx, "sprites/mur_3.xpm",
			&data->img_size.x, &data->img_size.y);
	data->f_img = mlx_xpm_file_to_image(data->mlx, "sprites/sol.xpm",
			&data->img_size.x, &data->img_size.y);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "sprites/player.xpm",
			&data->img_size.x, &data->img_size.y);
	data->c1_img = mlx_xpm_file_to_image(data->mlx,
			"sprites/collectible.xpm", &data->img_size.x, &data->img_size.y);
	data->c2_img = mlx_xpm_file_to_image(data->mlx,
			"sprites/collectible2.xpm", &data->img_size.x,
			&data->img_size.y);
	data->c3_img = mlx_xpm_file_to_image(data->mlx,
			"../sprites/collectible3.xpm", &data->img_size.x,
			&data->img_size.y);
	data->ex_img = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm",
			&data->img_size.x, &data->img_size.y);
	data->en_img = mlx_xpm_file_to_image(data->mlx, "sprites/enemy.xpm",
			&data->img_size.x, &data->img_size.y);
}

int	str_chr_end(char *str, char *strtofind)
{
	int		strlen;
	int		tofind_len;

	if (!str || !strtofind)
		return (0);
	tofind_len = ft_strlen(strtofind);
	strlen = ft_strlen(str);
	if (!tofind_len)
		return (1);
	if (strlen < tofind_len)
		return (0);
	str += strlen - tofind_len;
	while (*str || *strtofind)
	{
		if (*str++ != *strtofind++)
			return (0);
	}
	return (1);
}

int	validate_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("enter a unique map as argument"));
	if (!str_chr_end(argv[1], ".ber"))
		return (print_error("map format is not .ber"));
	return (1);
}
