/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:41:15 by oronda            #+#    #+#             */
/*   Updated: 2021/11/16 23:25:03 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_tilemap(t_game *data)
{
	int	i;

	i = 0;
	data->tilemap = (t_tile **)malloc(sizeof(t_tile *) * data->map_size.x);
	if (!data->tilemap)
		return (0);
	while (i < data->map_size.x)
	{
		data->tilemap[i] = (t_tile *)malloc(sizeof(t_tile) * data->map_size.y);
		if (!data->tilemap[i])
		{
			while (i > 0)
				free(data->tilemap[--i]);
			return (0);
		}
		i++;
	}
	return (1);
}

t_tiletype	get_tile_type(char c)
{
	if (c == 'E')
		return (EXIT);
	if (c == 'P')
		return (PLAYER);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (EMPTY);
	if (c == 'C')
		return (COLLECTIBLE);
	if (c == 'H')
		return (HORIZONTAL);
	if (c == 'V')
		return (VERTICAL);
	return (NOTHING);
}

int	fill_tilemap2(t_game *data, int x, int y, char buff)
{
	t_tiletype	type;

	type = get_tile_type(buff);
	data->tilemap[x][y].type = type;
	data->tilemap[x][y].position.x = x * SPRITE_SIZE;
	data->tilemap[x][y].position.y = y * SPRITE_SIZE;
	if (type == HORIZONTAL || type == VERTICAL)
		if (!add_enemy(data, type, &data->tilemap[x][y]))
			return (0);
	return (1);
}

int	fill_tilemap(int fd, t_game *data)
{
	int		x;
	int		y;
	int		r;
	char	buffer[1];

	r = 1;
	x = 0;
	y = 0;
	while (r)
	{
		r = read(fd, buffer, 1);
		if (r)
		{
			if (*buffer == '\n')
			{
				y++;
				x = 0;
			}
			else if (!fill_tilemap2(data, x++, y, *buffer))
				return (0);
		}
	}
	close(fd);
	return (1);
}

void	link_ajacent_tiles(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			data->tilemap[x][y].up = &data->tilemap[x][y - 1];
			data->tilemap[x][y].down = &data->tilemap[x][y + 1];
			data->tilemap[x][y].left = &data->tilemap[x - 1][y];
			data->tilemap[x][y].right = &data->tilemap[x + 1][y];
			x++;
		}
		y++;
	}
}
