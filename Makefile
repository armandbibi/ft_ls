# General
NAME			:= ft_ls
cc				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
SRC_DIR			:= srcs
OBJ_DIR			:= objs
INC_DIR			:= includes
LIB_DIR			:= ./libs

# LIB
LIB_FT_DIR		:= $(LIB_DIR)/libft
LIB_PF_DIR		:= $(LIB_DIR)/ft_printf
LIBFT_A			:= $(LIB_FT_DIR)/libft.a
PRINTF_A		:= $(LIB_PF_DIR)/libftprintf.a
LIBFT			:= -L$(LIB_FT_DIR) -lft
PRINTF			:= -L$(LIB_PF_DIR) -lftprintf

# FT_LS

SRCS			:=	main.c \
					ft_ls.c \

# SRCS FOR RUNNING PROJECT CONFORM TO CORRECTION
SRCS			:= main.c

# TERMINAL COMMANDS
MK				:= make -C
MK_C			:= make clean -C
MK_FC			:= make fclean -C
RM				:= /bin/rm -rf
MD				:= mkdir -p


# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

OBJS			:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

.PHONY: all clean fclean re

INCLUDE			:= -I $(LIB_FT_DIR) -I $(LIB_PF_DIR)/$(INC_DIR) -I $(INC_DIR)

all: $(LIB_DIR) $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF) $(INCLUDE)
	@echo "$(LOG_GREEN)FT_LS has been created successfully !$(LOG_NOCOLOR)"


$(LIB_DIR): $(LIBFT_A) $(PRINTF_A)

$(LIBFT_A):
	@$(MK) $(LIB_FT_DIR)

$(PRINTF_A):
	@$(MK) $(LIB_PF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MD) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	@$(MK_C) $(LIB_FT_DIR)
	@$(MK_C) $(LIB_PF_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(LOG_RED)Delete all Objects files ! $(LOG_NOCOLOR)"

fclean: clean
	@$(MK_FC) $(LIB_FT_DIR)
	@$(MK_FC) $(LIB_PF_DIR)
	@$(RM) $(NAME)
	@echo "$(LOG_RED)$(NAME) has been deleted !$(LOG_NOCOLOR)"

re: fclean all
