### General ###
NAME			:= ft_ls
cc				:= gcc
CFLAGS			:= -Wall -Werror -Wextra $(DEBUG)
SRC_DIR			:= srcs
OBJ_DIR			:= objs
INC_DIR			:= includes
LIB_DIR			:= ./libs

### LIB ###
LIB_FT_DIR		:= $(LIB_DIR)/libft
LIB_PF_DIR		:= $(LIB_DIR)/ft_printf
LIBFT_A			:= $(LIB_FT_DIR)/libft.a
PRINTF_A		:= $(LIB_PF_DIR)/libftprintf.a
LIBFT			:= -L$(LIB_FT_DIR) -lft
PRINTF			:= -L$(LIB_PF_DIR) -lftprintf

### TERMINAL COMMANDS ###
MK				:= make -C
MK_C			:= make clean -C
MK_FC			:= make fclean -C
RM				:= /bin/rm -rf
MD				:= mkdir -p

### COLORS ###
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

############################################
##############  FT_LS ######################
############################################

# DIRECTORIES

DIR_PARSE		:= parse/
DIR_PARSE_ARGS	:= parse/arguments/
DIR_PARSE_OPTS	:= parse/options/
DIR_MANAGE		:= dir_management
DIR_DISPLAY		:= display/

# INCLUDES

# SRCS FOR RUNNING PROJECT CONFORM TO CORRECTION
SRCS			+=	main.c

# inititlisation of function
SRCS			+=	ft_ls.c

# SRCS FOR PARSING


SRCS			+=	$(DIR_PARSE)ft_parse_ls.c \
					$(DIR_PARSE_ARGS)ft_ls_parse_arguments.c \
					$(DIR_PARSE_ARGS)ft_manage_undir_arguments.c \
					$(DIR_PARSE_OPTS)ft_parse_options.c \
					$(DIR_PARSE_OPTS)ft_add_option.c \
					$(DIR_PARSE_OPTS)set_display_options.c
					
# MALLOCS

SRCS			+=	$(DIR_MANAGE)/ft_malloc_ls.c \
					$(DIR_MANAGE)/ft_malloc_ls_dir.c \

# STRUCT LS_DIR

SRCS			+=	$(DIR_MANAGE)/add_dir_to_chain.c \
					$(DIR_MANAGE)/copy_stat_to_ls_dir.c \
					$(DIR_MANAGE)/ft_read_and_save_dir.c \

# DISPLAY

SRCS			+=	$(DIR_DISPLAY)display_bad_arguments.c\
					$(DIR_DISPLAY)display_files.c\
					$(DIR_DISPLAY)display_dir.c \
					$(DIR_DISPLAY)display_l.c \

# OBJECTS

OBJS			:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

###########################################
############ RULES ########################
###########################################


.PHONY: all clean fclean re

INCLUDE			:= -I $(LIB_FT_DIR) -I $(LIB_PF_DIR)/$(INC_DIR) -I $(INC_DIR)

all: $(LIB_DIR) $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF) $(INCLUDE)
	@echo "$(LOG_GREEN)FT_LS has been created successfully !$(LOG_NOCOLOR)"

$(LIB_DIR): $(LIBFT_A) $(PRINTF_A)

$(LIBFT_A):
	@$(MK) $(LIB_FT_DIR)
	@echo "$(LOG_GREEN)LIBFT.A IS READY$(LOG_NOCOLOR)"

$(PRINTF_A):
	@$(MK) $(LIB_PF_DIR)
	@echo "$(LOG_GREEN)FT_PRINTF.A IS READY$(LOG_NOCOLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(MD) $(OBJ_DIR)
	@$(MD) $(OBJ_DIR)/$(DIR_PARSE)
	@$(MD) $(OBJ_DIR)/$(DIR_MANAGE)
	@$(MD) $(OBJ_DIR)/$(DIR_DISPLAY)
	@$(MD) $(OBJ_DIR)/$(DIR_PARSE_ARGS)
	@$(MD) $(OBJ_DIR)/$(DIR_PARSE_OPTS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

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
