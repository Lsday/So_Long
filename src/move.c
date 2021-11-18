/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:51:40 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 15:43:12 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *data, t_tile *tiletomove)
{
	tiletomove->type = PLAYER;
	data->player.tile->type = EMPTY ;
	data->player.tile = tiletomove;
}

int	move_to_exit(t_game *data)
{
	if (!data->collects_count)
	{
		ft_putstr_fd("Gagné\n", 1);
		end_game(data);
	}
	else
		return (0);
	return (1);
}

void	move_to_enemy(t_game *data)
{
	ft_putstr_fd("PERDU\n", 1);
	end_game(data);
}

int	move(t_game *data, t_tile *tiletomove)
{
	if (!data->player.tile)
		return (0);
	if (tiletomove->type == WALL)
		return (0);
	if (tiletomove->type == EXIT)
	{
		if (!move_to_exit(data))
			return (0);
	}
	if (tiletomove->type == HORIZONTAL || tiletomove->type == VERTICAL)
		move_to_enemy(data);
	else
	{
		if (tiletomove->type == COLLECTIBLE)
			data->collects_count--;
		move_player(data, tiletomove);
	}
	return (1);
}
