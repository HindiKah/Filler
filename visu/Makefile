# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 17:29:05 by ybenoit           #+#    #+#              #
#    Updated: 2017/01/02 14:19:36 by ybenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=visu
FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

LIB_PATH=../libft
LIB=$(LIB_PATH)/libft.a
LIB_LINK=-L $(LIB_PATH) 

INC_DIR=includes
INCS=-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_DIR=srcs
SRC_BASE=main.c\
		init_n_maj.c\
		key_fun.c\
		drawer.c
		
OBJ_DIR=obj

#PREFIXE
SRCS=$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS=$(addprefix $(SRC_DIR)/, $(SRC_BASE:.c=.o))

#COLORS
C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"
C_ERROR="\033[31m"
C_WARN="\033[33m"

#DEBUG
SUCCESS=$(C_GOOD)SUCCESS$(C_NO)
OK=$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB_PATH)/libft.a
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

mclean: clean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

remain: mclean 
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB_PATH)/libft.a

re: fclean all


.PHONY: clean all re fclean
