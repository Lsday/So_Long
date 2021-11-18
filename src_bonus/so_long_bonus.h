/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:28:49 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 15:56:22 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifdef __linux__
#  define KEY_UP 122
#  define KEY_DOWN 115
#  define KEY_LEFT 113
#  define KEY_RIGHT 100
#  define KEY_ECHAP 65307

# elif __APPLE__
#  define KEY_UP 13
#  define KEY_DOWN 1
#  define KEY_LEFT 0
#  define KEY_RIGHT 2
#  define KEY_ECHAP 53
# endif

# define SPRITE_SIZE 64
# define DESTROYNOTIFY 17

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

typedef struct s_checker
{
	t_bool	player;
	t_bool	exit;
	t_bool	collectible;
}	t_checker;

typedef enum e_tiletype
{
	NOTHING,
	EMPTY,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER,
	HORIZONTAL,
	VERTICAL,
}	t_tiletype;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_direction;

typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

typedef struct s_tile
{
	t_tiletype		type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	t_tile	*tile;
	void	*img;
}	t_player;

// typedef enum e_enemytype
// {
// 	HORIZONTAL_ENEM = 'H',
// 	VERTICAL_ENEM = 'V',
// }	t_enemytype;

typedef struct s_enemy
{
	t_tiletype		type;
	int				dir;
	t_tile			*tile;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;		
	void		*window;	
	t_vector	w_size;	
	t_tile		**tilemap;
	t_vector	map_size;
	t_player	player;		

	int			start_collects_count;	
	int			collects_count;	
	int			moves_count;

	t_vector	img_size;
	void		*w_img;	
	void		*c1_img;
	void		*c2_img;
	void		*c3_img;	
	void		*ex_img;
	void		*f_img;
	void		*en_img;

	t_enemy		*enemy_lst;

}	t_game;

int			validate_map(t_game *data);
void		init_player(t_game *data);
void		init_collectible(t_game *data);
void		init_imgs(t_game *data);
int			get_width_and_height(int fd, t_game *data);
int			move(t_game *data, t_tile *tiletomove);
void		move_player(t_game *data, t_tile *tiletomove);
int			move_to_exit(t_game *data);
int			parse_map(char *map_path, t_game *data);
void		draw_images(t_game *data, int x, int y);
void		render(t_game *data);
int			create_tilemap(t_game *data);
t_tiletype	get_tile_type(char c);
int			fill_tilemap(int fd, t_game *data);
void		link_ajacent_tiles(t_game *data);
int			is_map_chars_valid(int fd);
int			is_char_valid(char c);
int			calculate(int *height, int *temp_width, int *width, int fd);
int			is_enclosed(t_game *data);
int			check_player_nb(t_game *data);
int			check_exit_nb(t_game *data);
int			check_collectible_nb(t_game *data);
void		free_tilemap(t_game *data);
int			end_game(t_game *data);
int			print_error(char *message);
int			validate_args(int argc, char **argv);
int			str_chr_end(char *str, char *strtofind);
void		print_nb_to_screen(t_game *data, int nb);
int			add_enemy(t_game *data, t_tiletype emy_type, t_tile *tile);
void		move_enemy(t_enemy *enemy, t_game *data);
void		free_enemy(t_enemy *enemy_lst);
void		anim(t_game *data);
void		move_enemies(t_game *data);

#endif