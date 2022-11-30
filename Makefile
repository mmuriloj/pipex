NAME			= pipex

HEADERS_DIR 	= ./includes/
SOURCES_DIR		= ./sources/

HEADERS_LIST	= pipex.h
SOURCES_LIST	= pipex.c \
				execute.c

HEADERS			= ${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			= ${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		= -I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		= ./objects/
OBJECTS_LIST	= ${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJS			= $(SOURCES_LIST:.c=.o)
OBJECTS			= ${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT			= ${LIBFT_DIR}libft.a
LIBFT_DIR		= ./libft/
LIBFT_HEADERS	= ${LIBFT_DIR}includes/

CC				= cc
CFLAGS			= -Wall -Werror -Wextra

RM 				= rm -f

all: ${NAME}

libft: ${LIBFT}

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} ${INCLUDES} -o ${NAME}

${OBJECTS_DIR}:
	mkdir -p ${OBJECTS_DIR}

${OBJS} : ${SOURCES}
	${CC} ${CFLAGS} -c ${SOURCES}
	mv *.o ./objects/

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

${LIBFT}:
	clear && make -sC ${LIBFT_DIR}

clean:
	make -sC ${LIBFT_DIR} clean
	rm -rf ${OBJECTS_DIR}

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re:	fclean all

.PHONY:		all, clean, fclean, re