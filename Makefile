NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRC = 	push_swap.c			\
		arr.c				\
		arr_utils.c			\
		rr.c				\
		rrr.c				\
		sort_rotate.c		\
		sort_rotate_utl.c	\
		sort_utl.c			\
		sort.c				\
		sp.c				\
		split.c				\
		utls.c				\

OBJECTS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS)
%.o	:	%.c
	gcc $(CFLAGS) -c $^ -I./ -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean