NAME		= pipex
MKDIR		= mkdir -p
CC			= cc
INCLUDES 	= -Iincludes
CFLAGS		= -Wall -Wextra -Werror -g
SRCS_DIR	= sources
SRCS		= $(wildcard sources/*.c) $(wildcard *.c)
OBJS		= $(patsubst sources/%.c, objs/%.o,$(SRCS))
OBJS_DIR	= objs
RM			= rm -rf

.DEFAULT_GOAL = all

$(OBJS_DIR)/%.o: sources/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o $@

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo " \033[38;2;255;127;80m" "Done"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)
	@echo " \033[0;31m" "Clean up"

re: fclean all

.PHONY: all clean fclean re
