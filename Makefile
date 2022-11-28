TESTE = clear && gcc srcs/teste.c libft/libft.a -o teste && ./teste

all:
	clear

teste:
	rm -rf teste
	$(TESTE)