NAME			= philo 
MKDIR			= mkdir -p
CC				= cc
INCLUDES 		= -Iincludes
LINKER			= -lpthread
CFLAGS			= -Wall -Wextra -Werror -g -ggdb3
SRCS_DIR		= sources
LIBFT_DIR		= libft
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
LIBFT_SRCS		= $(wildcard $(LIBFT_DIR)/*.c)
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)) 
LIBFT_OBJS		= $(patsubst $(LIBFT_DIR)/%.c, $(OBJS_DIR)/%.o, $(LIBFT_SRCS))
RM				= rm -rf

RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_OBJS)
	@echo $(YELLOW) " - Compiling $(NAME)..." $(RESET)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT_OBJS) $(LINKER) -o $(NAME)
	@echo $(GREEN)" - Compiling FINISHED"$(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o : $(LIBFT_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@echo  $(RED) " - Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
