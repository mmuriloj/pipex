NAME			=	pipex

HEADERS_DIR 	=	./includes/
SOURCES_DIR		=	./srcs/

HEADERS_LIST	=	pipex.h
SOURCES_LIST	=	pipex.c \
					execute.c \
					check.c \
					pipex_error.c \
					fix_command.c

HEADERS			=	${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			=	${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		=	-I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		=	./objs/
OBJECTS_LIST	=	${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJS			=	$(SOURCES_LIST:.c=.o)
OBJECTS			=	${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT			=	${LIBFT_DIR}libft.a
LIBFT_DIR		=	./libft/
LIBFT_HEADERS	=	${LIBFT_DIR}includes/

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g

all: ${NAME}

libft: ${LIBFT}

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} ${INCLUDES} -o ${NAME}
	@echo "\033[1;92mPipex created successfully!\033[0m"

${OBJECTS_DIR}:
	mkdir -p ${OBJECTS_DIR}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

${LIBFT}:
	clear && make -sC ${LIBFT_DIR}

clean:
	clear
	@make -sC ${LIBFT_DIR} clean
	@echo "Removing pipex objects..."
	@rm -rf ${OBJECTS_DIR}

fclean: clean
	@echo "Removing Libft..."
	@rm -rf ${LIBFT}
	@echo "\033[31mLibft removed successfully!\033[0m"
	@echo "Removing pipex..."
	@rm -rf ${NAME}
	@echo "\033[31mPipex removed successfully!\033[0m"

re:	fclean all

.PHONY:		all, clean, fclean, re