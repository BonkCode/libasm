#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "lorem.h"

size_t		ft_strlen(char *str);

int main(void)
{
	printf("ORIG: %lu\n", strlen("WHY ME?"));
	printf("MY: %lu\n", ft_strlen("WHY ME?"));
	printf("ORIG: %lu\n", strlen("sHuSH?"));
	printf("MY: %lu\n", ft_strlen("sHuSH?"));
	printf("ORIG: %lu\n", strlen("hello, name's james"));
	printf("MY: %lu\n", ft_strlen("hello, name's james"));
	printf("ORIG: %lu\n", strlen(""));
	printf("MY: %lu\n", ft_strlen(""));
	printf("ORIG: %lu\n", strlen("a"));
	printf("MY: %lu\n", ft_strlen("a"));
	printf("ORIG: %lu\n", strlen("no?\n\n\n\n\t"));
	printf("MY: %lu\n", ft_strlen("no?\n\n\n\n\t"));
	printf("ORIG: %lu\n", strlen("da"));
	printf("MY: %lu\n", ft_strlen("da"));
	printf("ORIG: %lu\n", strlen(LOREM));
	printf("MY: %lu\n", ft_strlen(LOREM));
}
