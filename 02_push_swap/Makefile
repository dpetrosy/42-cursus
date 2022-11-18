NAME			= push_swap 
CHECKER			= checker
MKDIR			= mkdir -p
CC				= cc
INCLUDES 		= -Iincludes -Ilibft -Ift_printf/include
CFLAGS			= -Wall -Wextra -Werror -g
SRCS_DIR		= sources
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
CHECKER_DIR		= checker_bonus
CHECKER_SRCS	= $(wildcard $(CHECKER_DIR)/$(SRCS_DIR)/*.c)
CHECKER_INCLUDE	= -Ichecker_bonus/includes -Ilibft -Ift_printf/include
OBJS_DIR		= objs
OBJS_DIR_BONUS	= objs_bonus
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS		= $(patsubst $(CHECKER_DIR)/$(SRCS_DIR)/%.c, $(OBJS_DIR_BONUS)/%.o, $(CHECKER_SRCS))
LIBFT_A			= libft.a
LIBFT_DIR		= libft/
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_A))
FT_PRINTF_A		= libftprintf.a
FT_PRINTF_DIR	= ft_printf/
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))
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

$(NAME) : $(OBJS)
	@echo $(GREEN) " - Making libft..." $(RESET)
	@make -s -C $(LIBFT_DIR)
	@echo $(BLUE) " - Made libft!" $(RESET)
	@echo $(GREEN) " - Making printf..." $(RESET)
	@make -s -C $(FT_PRINTF_DIR)
	@echo $(BLUE) " - Made printf!" $(RESET)
	@echo $(MAGENTA) " - Compiling $(NAME)..." $(RESET)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo $(BLUE)"- Compiling FINISHED"$(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/*.o $(LIBFT_DIR)/$(LIBFT_A)
	@$(RM) $(FT_PRINTF_DIR)/src/*.o $(FT_PRINTF_DIR)/$(FT_PRINTF_A)
	@echo  $(RED) " - Cleaned!" $(RESET)

re: fclean all

bonus : $(CHECKER)
	
$(CHECKER) : $(OBJS_BONUS)
	@echo $(GREEN) " - Making libft..." $(RESET)
	@make -s -C $(LIBFT_DIR)
	@echo $(BLUE) " - Made libft!" $(RESET)
	@echo $(GREEN) " - Making printf..." $(RESET)
	@make -s -C $(FT_PRINTF_DIR)
	@echo $(BLUE) " - Made printf!" $(RESET)
	@echo $(MAGENTA) " - Compiling $(CHECKER)..." $(RESET)
	@gcc $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) -o $(CHECKER)
	@echo $(BLUE)"- Compiling FINISHED"$(RESET)

$(OBJS_DIR_BONUS)/%.o : $(CHECKER_DIR)/$(SRCS_DIR)/%.c | $(OBJS_DIR_BONUS)
	@$(CC) $(CFLAGS) $(CHECKER_INCLUDE) -c $< -o $@

$(OBJS_DIR_BONUS) :
	@$(MKDIR) $(OBJS_DIR_BONUS)

clean_bonus :
	@$(RM) $(OBJS_DIR_BONUS)

fclean_bonus : clean_bonus
	@$(RM) $(CHECKER)
	@$(RM) $(LIBFT_DIR)/*.o $(LIBFT_DIR)/$(LIBFT_A)
	@$(RM) $(FT_PRINTF_DIR)/src/*.o $(FT_PRINTF_DIR)/$(FT_PRINTF_A)
	@echo  $(RED) " - Cleaned!" $(RESET)

bonus_re : fclean_bonus bonus

.PHONY: all clean fclean re
