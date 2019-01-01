NAME := samukano.filler
CFLAGS := -Wall -Wextra -Werror
SOURCE := filler.c helper.c helper2.c helper3.c

OBJ := $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -c $(SOURCE)

%.o:%.c
	cd libft && $(MAKE)
	gcc $(CFLAGS) -o $(NAME) $(SOURCE) libft/libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
