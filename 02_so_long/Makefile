NAME			= so_long
MKDIR			= mkdir -p
CC				= cc
OS				= $(shell uname)
INCLUDES 		= -Iincludes -Ilibft -Ift_printf/include
CFLAGS			= -Wall -Wextra -Werror
SRCS_DIR		= sources
SRCS			= $(wildcard $(SRCS_DIR)/*.c) 
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)) 
LIBFT_A			= libft.a
LIBFT_DIR		= libft/
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_A))
FT_PRINTF_A		= libftprintf.a
FT_PRINTF_DIR	= ft_printf/
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))
RM				= rm -rf

ifeq ($(OS), Linux)
	MLX = mlx_linux
	LINKER = -lmlx -lm -lXext -lX11
	INCLUDES := $(INCLUDES) -Imlx_linux
else
	MLX = mlx_macos
	LINKER = -lmlx -lm -framework OpenGl -framework Appkit
	INCLUDES := $(INCLUDES) -Imlx_macos
endif

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
	@echo $(GREEN) " - Making mlx..." $(RESET)
	@make -s -C $(MLX)
	@echo $(BLUE) " - Made mlx!" $(RESET)
	@echo $(MAGENTA) " - Compiling $(NAME)..." $(RESET)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -L $(MLX) -o $(NAME) $(LINKER)
	@echo $(BLUE)"- Compiling FINISHED"$(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -g -ggdb3 $< -o $@

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/*.o $(LIBFT_DIR)/$(LIBFT_A)
	@$(RM) $(FT_PRINTF_DIR)/src/*.o $(FT_PRINTF_DIR)/$(FT_PRINTF_A)
	@echo  $(RED) " - Cleaned!" $(RESET)
	@make -s clean -C $(MLX)

re: fclean all

.PHONY: all clean fclean re
