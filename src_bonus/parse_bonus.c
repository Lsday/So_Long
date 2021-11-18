/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:50:24 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:16:13 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	parse_map(char *map_path, t_game *data)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!get_width_and_height(fd, data))
	{
		close(fd);
		return (0);
	}
	if (!create_tilemap(data))
		end_game(data);
	fd = open(map_path, O_RDONLY);
	data->enemy_lst = NULL;
	if (!fill_tilemap(fd, data))
		return (print_error("malloc failed"));
	link_ajacent_tiles(data);
	return (1);
}
