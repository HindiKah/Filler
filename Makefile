CC=gcc
NAME=ybenoit

SRCS_DIR=srcs
SRC_BASE=main.c\
		 parsing.c\
		 testing.c

C_FILE=$(addprefix $(SRCS_DIR)/,$(SRC_BASE))
O_FILE=$(addprefix $(SRCS_DIR)/,$(SRC_BASE:.c=.o))

all: $(NAME)

$(NAME): obj
	$(CC) -o $(NAME) ./*.o ./libft/libft.a

obj: lib
	$(CC) -c $(C_FILE) ./includes/filler.h

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

remain: clean_main all

.PHONY: clean all re fclean
