SRCS= main.cpp \
	  Base.cpp \

CXX= c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS= ${SRCS:.cpp=.o}

NAME= identify

%.o: %.cpp
	${CXX} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f ${NAME}

re: fclean all

