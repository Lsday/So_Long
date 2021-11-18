SRCS =  src/main.c		\
		src/checker.c	\
		src/errors.c	\
		src/free.c		\
		src/init.c		\
		src/map.c		\
		src/move.c		\
		src/parse.c		\
		src/render.c	\
		src/tilemap.c	\
		src/enemy.c		\
		src/utils.c	
	
SRCS_BONUS =    src_bonus/main_bonus.c		\
				src_bonus/checker_bonus.c	\
				src_bonus/enemy.c			\
				src_bonus/enemy_move.c		\
				src_bonus/errors_bonus.c	\
				src_bonus/free_bonus.c		\
				src_bonus/init_bonus.c		\
				src_bonus/map_bonus.c		\
				src_bonus/move_bonus.c		\
				src_bonus/parse_bonus.c		\
				src_bonus/render_bonus.c	\
				src_bonus/tilemap_bonus.c	\
				src_bonus/anims.c			\
				src_bonus/utils_bonus.c	

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef INCLUDE_BONUSES
OBJS_LIST = $(OBJS_BONUS)
else
OBJS_LIST = $(OBJS)
endif

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

# $< = first prerequisite (= xxxx.c = c files)
# $(<:.c=.o) = xxxx.c to xxxx.o (simply changes .c to .o on file name)
# -I = search for headers in this directory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS_LIST) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_LIST) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

bonus:		
	$(MAKE) INCLUDE_BONUSES=1

$(LIBFT):
	$(MAKE) -C libft

all:		$(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus