##
## EPITECH PROJECT, 2024
## syn_pool
## File description:
## Makefile
##

CC	= g++

NAME	=  abstractVM

SRC	=	src/main.cpp \
		src/Factory.cpp \
		src/Int8.cpp \
		src/Int16.cpp \
		src/Int32.cpp \
		src/error.cpp \
		src/Operand.cpp \
		src/Float.cpp \
		src/Double.cpp \
		src/AbstractVM.cpp \

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS += -I./include

CFLAGS += -std=c++20 -Wall -Wextra -Werror -g3 -g

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -g3 -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean