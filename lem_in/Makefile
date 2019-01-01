NAME := lem-in
CFLAGS := -Wall -Wextra -Werror
SOURCE := main.c helper1.c helper2.c helper3.c helper4.c fta.c pr.c last.c
OBJ := main.o helper1.o helper2.o helper3.o helper4.o fta.o pr.o last.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SOURCE)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
