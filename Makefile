NAME = minishell
INC  = minishell.h
SRCS = 	main.c \
		minishell.c \
		utile.c \
		utile2.c\
		signal.c\
		environment.c\
		check_line.c\
		tokens.c\
		replace_env.c\
		riderection.c\
		check_quot.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline -lncurses $^ -o $(NAME) -L ~/goinfre/.brew/opt/readline/lib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ~/goinfre/.brew/opt/readline/include

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
