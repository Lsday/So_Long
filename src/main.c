/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:40:16 by oronda            #+#    #+#             */
/*   Updated: 2021/11/22 13:55:48 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *data)
{
	if (!is_enclosed(data))
		return (print_error("map is not enclosed with walls"));
	if (!check_player_nb(data))
		return (print_error("wrong number of player"));
	if (!check_exit_nb(data))
		return (print_error("wrong number of exit"));
	if (!check_collectible_nb(data))
		return (print_error("no collectibles"));
	return (1);
}

int	ft_keyboard_input(int keycode, void *g_data)
{	
	t_game	*data;
	int		has_moved;

	has_moved = 0;
	data = (t_game *)g_data;
	if (keycode == KEY_UP)
		has_moved = move(data, data->player.tile->up);
	if (keycode == KEY_DOWN)
		has_moved = move(data, data->player.tile->down);
	if (keycode == KEY_LEFT)
		has_moved = move(data, data->player.tile->left);
	if (keycode == KEY_RIGHT)
		has_moved = move(data, data->player.tile->right);
	if (keycode == KEY_ECHAP)
		end_game(data);
	if (has_moved)
	{
		data->moves_count++;
		ft_putstr_fd("move = ", 1);
		ft_putnbr_fd(data->moves_count, 1);
		ft_putstr_fd("\n", 1);
		render(data);
	}
	return (0);
}

int	exit_hook(void *g_data)
{
	t_game	*data;

	data = (t_game *)g_data;
	end_game(data);
	return (0);
}

void	init(t_game *data)
{
	init_player(data);
	init_collectible(data);
	data->mlx = mlx_init();
	init_imgs(data);
	data->moves_count = 0;
	data->w_size.x = data->map_size.x * SPRITE_SIZE;
	data->w_size.y = data->map_size.y * SPRITE_SIZE;
	data->window = mlx_new_window(data->mlx, data->w_size.x,
			data->w_size.y, "SO_LONG");
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	data;

	if (!validate_args(argc, argv))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (print_error("file not found"));
	if (!is_map_chars_valid(fd))
		return (print_error("a char is invalid"));
	if (!parse_map(argv[1], &data))
		return (0);
	if (!validate_map(&data))
		end_game(&data);
	init(&data);
	mlx_key_hook(data.window, &ft_keyboard_input, &data);
	mlx_hook(data.window, DESTROYNOTIFY,
		1L << 17, exit_hook, &data);
	render(&data);
	mlx_loop(data.mlx);
}
