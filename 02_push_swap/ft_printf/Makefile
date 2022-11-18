.PHONY: all re clean fclean

FOLDER	= src
SOURCES	= $(wildcard $(FOLDER)/*.c)
OBJECTS	= $(SOURCES:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
RM		= rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	@$(RM) $(OBJECTS)

fclean : clean
	@$(RM) $(NAME)
