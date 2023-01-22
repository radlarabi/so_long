SRCS =  srcs/main.c \
		srcs/utiles1.c \
		srcs/utiles2.c \
		srcs/utiles3.c \
		srcs/utiles4.c \
		srcs/utiles5.c \
		srcs/moves.c \
		srcs/initiale_animation.c \
		srcs/display_images.c \
		get_next_line/ft_itoa.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

NAME = so_long
CC = cc
RM = rm -rf
# CFLAGS = -Wall -Wextra -Werror

O_SRCS = $(SRCS:%.c=%.o obj)

all: $(NAME)

$(NAME): $(O_SRCS)
	$(CC) $(O_SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(O_SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re