NAME = ft_cat

SRCS_PATH = ./srcs

OBJS_PATH = ./objs

SRCS = ft_cat.c

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
