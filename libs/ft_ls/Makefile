# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:01:09 by abiestro          #+#    #+#              #
#    Updated: 2018/10/22 17:01:23 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_ls.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PATH_INCLUDES	= ./includes
PATH_SOURCES	= ./srcs
PATH_OBJS		= ./objs

INCLUDES		= ft_ls.h 

ITEMS			= 

OBJS			= $(addprefix $(PATH_OBJS)/, $(ITEMS:=.o))
OBJS			+= $(addprefix $(PATH_OBJS)/, $(LIB_NEEDED:=.o))
INCLUDES		= $(addprefix $(PATH_INCLUDES)/, ft_printf.h)

.PHONY : all clean fclean re
all:$(NAME)

$(NAME):$(OBJS)
		@echo "objects builded..."
		@ar -rcs $(NAME) $(OBJS) $(OBJS_EXTRA)
		@echo $(NAME) "ready!"

$(OBJS) : |$(PATH_OBJS)

$(PATH_OBJS) :
	@mkdir objs

$(PATH_OBJS)/%.o : $(PATH_SOURCES)/%.c
	@$(CC) -c $(CFLAGS)  $<  -o $@
	@echo "builded -->" $@

clean:
		@rm -rf $(PATH_OBJS)
		@echo "objects removed 😇 "

fclean: clean
		@rm -f $(NAME)
		@echo $(NAME) "removed 😇 "

re: fclean all

