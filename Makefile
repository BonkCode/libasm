SRCS = srcs/ft_read.s srcs/ft_write.s srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strdup.s srcs/test.s
OBJS = $(SRCS:.s=.o)

NASM = nasm
FLAG = -f macho64

NAME = libasm.a

all: $(NAME)

$(NAME): $(OBJS)
	gcc srcs/main.c $(OBJS)
	./a.out

%.o: %.s
	$(NASM) $(FLAG) $<