SRCS = srcs/ft_read.s srcs/ft_write.s srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strdup.s srcs/ft_strcmp.s
OBJS = $(SRCS:.s=.o)

NASM = nasm
FLAG = -f macho64

NAME = libasm.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.s
	$(NASM) $(FLAG) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

test: $(NAME)
	gcc tests/main.c $(NAME)
	./a.out

.PHONY: all clean fclean re test