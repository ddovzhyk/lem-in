.PHONY: libft.a

NAME = lem-in
FLAGS = -Wextra -Wall -Werror
LIBOBJ = ./libft/*.o
OBJECTS =							\
		main.o						\
		input.o						\
		reading_links.o				\
		reading_rooms.o				\
		find_ways_and_run_ants.o	\
		funcs_for_find_ways.o		\
		useful_funcs.o				\

all : $(NAME)

$(NAME) : libft.a $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -I . -I ./libft ./libft/libft.a

libft.a:
	make -C ./libft

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I . -I ./libft

clean :
	make clean -C ./libft
	rm -f $(OBJECTS)
	rm -f *.c~

fclean : clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re : fclean all