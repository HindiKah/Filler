CC=gcc
NAME=ybenoit.filler

FLAGS= -g -Wall -Wextra -Werror

SRCS_DIR=srcs
SRC_BASE=main.c\
		 parsing.c\
		 tab_fun.c\
		 testing.c\
		 analyse.c\
		 checker_line.c\
		 checker_line2.c\
		 analyse_map.c\
		 give_position.c\
		 search_way.c\
		 resizing.c\
		 resizing2.c

C_FILE=$(addprefix $(SRCS_DIR)/,$(SRC_BASE))
O_FILE=$(addprefix $(SRCS_DIR)/,$(SRC_BASE:.c=.o))

all: $(NAME)

$(NAME): obj
	$(CC) -o $(NAME) ./*.o ./libft/libft.a

obj: lib
	$(CC) -c $(FLAGS) $(C_FILE) ./includes/filler.h

lib:
	make -C libft all 

clean:
	rm -rf *.o
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	rm libft/libft.a

re: fclean all

clean_main:
	rm -rf *.o
	rm -rf $(NAME)

remain: clean_main ybenoit

.PHONY: clean all re fclean
