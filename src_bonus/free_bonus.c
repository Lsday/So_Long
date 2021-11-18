/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:06:22 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 15:24:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	free_enemy(t_enemy *enemy_lst)
{
	t_enemy	*next;

	if (!enemy_lst)
		return ;
	while (enemy_lst->next)
	{
		next = enemy_lst->next;
		free(enemy_lst);
		enemy_lst = next;
	}
	free(enemy_lst);
}

int	end_game(t_game *data)
{
	free_enemy(data->enemy_lst);
	free_tilemap(data);
	data->tilemap = NULL;
	exit(0);
}
