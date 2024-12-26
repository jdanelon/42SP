NAME = ft_tail

SRCS_PATH = ./srcs

OBJS_PATH = ./objs

SRCS = ft_tail.c

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
