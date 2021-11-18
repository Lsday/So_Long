/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:10:50 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:16:03 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*create_enemy(t_tiletype type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->tile = tile;
	enemy->type = type;
	enemy->dir = 0;
	enemy->next = NULL;
	return (enemy);
}

void	add_last(t_enemy *lst, t_enemy *enemy)
{
	if (!lst)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = enemy;
}

int	add_enemy(t_game *data, t_tiletype emy_type, t_tile *tile)
{
	t_enemy	*new;

	new = create_enemy(emy_type, tile);
	if (!new)
		return (0);
	if (data->enemy_lst == NULL)
		data->enemy_lst = new;
	else
		add_last(data->enemy_lst, new);
	return (1);
}
