/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:18:05 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:19:35 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_can_move(t_enemy *enemy, t_tile *tiletomove, t_game *data)
{
	if (tiletomove->type == PLAYER)
	{
		render(data);
		ft_putstr_fd("PERDU\n", 1);
		end_game(data);
		return (0);
	}
	if (tiletomove->type != EMPTY)
	{
		if (enemy->dir == 1)
			enemy->dir = 0;
		else if (enemy->dir == 0)
			enemy->dir = 1;
		return (0);
	}
	else
		return (1);
}

void	move_horizontal(t_game *data, t_enemy *enemy)
{
	if (enemy->dir == 0)
	{
		if (!enemy_can_move(enemy, enemy->tile->left, data))
			return ;
		enemy->tile->type = EMPTY;
		enemy->tile = enemy->tile->left;
		enemy->tile->type = HORIZONTAL;
	}
	else
	{
		if (!enemy_can_move(enemy, enemy->tile->right, data))
			return ;
		enemy->tile->type = EMPTY;
		enemy->tile = enemy->tile->right;
		enemy->tile->type = HORIZONTAL;
	}
}

void	move_vertical(t_game *data, t_enemy *enemy)
{
	if (enemy->dir == 0)
	{
		if (!enemy_can_move(enemy, enemy->tile->up, data))
			return ;
		enemy->tile->type = EMPTY;
		enemy->tile = enemy->tile->up;
		enemy->tile->type = HORIZONTAL;
	}
	else
	{
		if (!enemy_can_move(enemy, enemy->tile->down, data))
			return ;
		enemy->tile->type = EMPTY;
		enemy->tile = enemy->tile->down;
		enemy->tile->type = HORIZONTAL;
	}
}

void	move_enemy(t_enemy *enemy, t_game *data)
{
	if (enemy->type == HORIZONTAL)
		move_horizontal(data, enemy);
	else if (enemy->type == VERTICAL)
		move_vertical(data, enemy);
}

void	move_enemies(t_game *data)
{
	t_enemy	*enemylist;

	enemylist = data->enemy_lst;
	while (enemylist)
	{
		move_enemy(enemylist, data);
		enemylist = enemylist->next;
	}
}
