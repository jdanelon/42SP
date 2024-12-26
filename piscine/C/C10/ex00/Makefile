NAME = ft_display_file

SRCS_PATH = ./srcs

OBJS_PATH = ./objs

SRCS = ft_display_file.c \
		ft_putstr_fd.c

OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

INCLUDES = ./includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) -g $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
