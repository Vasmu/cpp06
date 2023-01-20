SRCS= main.cpp \
	  Scale.cpp \

CC= c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS= ${SRCS:.c=.o}

NAME= convert

%.o: %.c
	${CC} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f ${NAME}

re: fclean all

