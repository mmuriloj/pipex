NAME = libft.a
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra -c
HEADER = ./includes/ft_printf.h
SRCS =  ft_atoi.c ft_isprint.c ft_printf.c \
		ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
		ft_bzero.c ft_itoa.c ft_print_hex.c \
		ft_split.c ft_strlen.c ft_tolower.c \
		ft_calloc.c ft_memchr.c ft_print_num.c \
		ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_isalnum.c ft_memcmp.c ft_print_ptr.c \
		ft_strdup.c ft_strncmp.c get_next_line.c \
		ft_isalpha.c ft_memcpy.c ft_putchar_fd.c \
		ft_striteri.c ft_strnstr.c get_next_line_utils.c \
		ft_isascii.c ft_memmove.c ft_putendl_fd.c \
		ft_strjoin.c ft_strrchr.c ft_isdigit.c \
		ft_memset.c ft_putnbr_fd.c ft_strlcat.c \
		ft_strtrim.c
OBJS =	 $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	 $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "\033[1;92mLibft created successfully!\033[0m"

$(OBJS):	$(SRCS)
	@echo "Creating libft objects..."
	$(CC) $(CFLAGS) $(SRCS)

clean:
	@echo "Removing libft objects..."
	rm -rf $(OBJS) 

fclean: clean
	@echo "Removing libft.a ..."
	rm -rf $(NAME)
	@echo "\033[1;92mLibft removed successfully!\033[0m"

re: fclean all

.PHONY: re fclean clean all