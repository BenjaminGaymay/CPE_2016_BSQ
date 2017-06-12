##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
## 
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
## 
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Wed Dec 14 11:23:56 2016 Benjamin GAYMAY
##

CC	=	gcc

RM	=	rm -f

NAME	=	bsq

LIB	=	-L./lib/ -lmy

CFLAGS	+=	-I./include

SRCS	=	main.c \
		my_bsq.c \
		check_square.c \
		use_array.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/
	$(CC) $(OBJS) -o $(NAME) $(LIB)
	rm lib/libmy.a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
