# General

NAME		:= ft_ls
cc			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
SRC_DIR		:= srcs
OBJ_DIR		:= objs
INC_DIR		:= includes
LIB_DIR		:= libs

# LIB

LIB_FT_DIR	:= $(LIB_DIR)/libft
LIB_PF_DIR	:= $(LIB_DIR)/ft_printf
LIBFT_A		:= $(LIB_FT_DIR)/libft.a
PRINTF_A	:= $(LIB_PF_DIR)/libftprintf.a
LIBFT		:= -L$(LIB_FT_DIR) -lft
PRINTF		:= -L$(LIB_PF_DIR) -lftprintf

# FT_LS

LIB_LS_DIR	:= $(LIB_DIR)/ft_ls
FT_LS_A		:= $(LIB_LS_DIR)/ft_ls


# TERMINAL COMMANDS
MK		:= make -C
MK_C	:= make clean -C
MK_FC	:= make fclean -C
RM		:= /bin/rm -rf
MD		:= mkdir -p


# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

.PHONY: all clean fclean re

all: $(LIB_DIR) $(NAME)

$(LIB_DIR): $(LIBFT_A) $(PRINTF_A)


$(LIBFT_A):
	@$(MK) $(LIB_FT_DIR)

$(PRINTF_A):
	@$(MK) $(LIB_PF_DIR)


clean:
	@$(MK_C) $(LIB_FT_DIR)
	@$(MK_C) $(LIB_PF_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(LOG_RED)Delete all Objects files ! $(LOG_NOCOLOR)"

fclean: clean
	@$(MK_FC) $(LIB_FT_DIR)
	@$(MK_FC) $(LIB_PF_DIR)
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
	@echo "$(LOG_RED)$(NAME1) and $(NAME2) has been deleted !$(LOG_NOCOLOR)"

re: fclean all
