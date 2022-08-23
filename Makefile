##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile the project
##
	
SRC			=	src/display.c\
				src/fill_boat.c\
				src/main.c\
				src/test.c\
				src/change_map.c\
				src/connection.c\
				src/send.c\
				src/receive.c\
				src/attack.c\
				src/alloc_attack.c\
				src/attaque_recive.c\
				src/game.c\
				src/win.c\

NAME		=	navy

all:	$(NAME)

$(NAME):
	make -C lib/printf
	make -C lib/my
	gcc -o $(NAME) $(SRC) -L ./lib/my -lmy -L ./lib/printf -lprintf -g3

clean:
	rm -f *~
	rm -f *#
	rm -f src/*tmp
	rm -f lib/my/libmy.a
	rm -f lib/libmy.a

fclean: clean
	make fclean -C lib/my
	make fclean -C lib/printf
	rm -f $(NAME)
	rm -f unit*
	rm -f vg*

re:	fclean all
