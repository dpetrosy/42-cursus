NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

ALL_SRCS = $(wildcard *.c)

BONUS_SRCS = $(wildcard ft_lst*.c)

SRCS = $(filter-out $(BONUS_SRCS), $(ALL_SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))

BONUS_OBJS = $(patsubst %.c, %.o, $(BONUS_SRCS))

AR = ar rcs

RM = rm -f

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
