#include "lorem.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *src);
char		*test_func(char *dst, char *src);

void write_test()
{
	int ret;
	int fd;

	printf("==============TESTING WRITE=============\n");
	printf("STDIN\nORIGINAL\n");
	ret = write(1, "Hello World!\n", 13);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	ret = ft_write(1, "Hello World!\n", 13);
	printf("MY WRITE RET: %i\n", ret);
	printf("STDIN\nERRNO CHECK\n");
	errno = 0;
	ret = write(-21, "Hello World!\n", 13);
	printf("original errno: %i\n", errno);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	errno = 0;
	ret = ft_write(21, "Hello World!\n", 13);
	printf("MY WRITE RET: %i\n", ret);
	printf("my errno: %i\n", errno);
}

void read_test()
{
	int ret;
	int fd;
	char rr[4];

	printf("==============TESTING READ=============\n");
	printf("FILE\nORIGINAL\n");
	fd = open("2.txt", O_RDONLY);
	ret = read(fd, rr, 23);
	rr[3] = '\0';
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf("WAS READ: %s\n", rr);
	close(fd);
	fd = open("2.txt", O_RDONLY);
	ret = ft_read(fd, rr, 4096);
	rr[3] = '\0';
	printf("MY READ RET: %i\n", ret);
	printf("WAS READ: %s\n", rr);
}

void strlen_test()
{
	printf("==============TESTING STRLEN=============\n");
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
//	printf("ORIG: %lu\n", strlen(NULL));
	printf("MY: %lu\n", ft_strlen(NULL));
}

void strcpy_test()
{
	int fd;
	char *dst;
	char src[4097];
	printf("==============TESTING STRCPY=============\n");
	fd = open("2.txt", O_RDONLY);
	ft_read(fd, src, 4096);
	close(fd);
	dst = malloc(10);
	strcpy(dst, src);
	printf ("ORIG: %s\n", dst);
	free(dst);
	dst = malloc(10);
	ft_strcpy(dst, src);
	printf ("MY: %s\n", dst);
	free(dst);
	dst = malloc(10);
	strcpy(dst, "DADAYA");
	printf ("ORIG: %s\n", dst);
	free(dst);
	dst = malloc(10);
	ft_strcpy(dst, "DADAYA");
	printf ("MY: %s\n", dst);
	free(dst);
	dst = malloc(10);
	strcpy(dst, "");
	printf ("ORIG: %s\n", dst);
	free(dst);
	dst = malloc(10);
	ft_strcpy(dst, "");
	printf ("MY: %s\n", dst);
	free(dst);
}

void strdup_test()
{
	char *ptr;
	char *dst;

	dst = malloc(32);
	printf("==============TESTING STRDUP=============\n");
	printf ("test: %s\n", test_func(dst, "dada ya, pelmeni norm tema ksta"));
	printf ("strcpy: %s\n", ft_strcpy(dst, "dada ya, pelmeni norm tema ksta"));
	printf ("ORIG: %s\n", strdup("dada ya, pelmeni norm tema ksta"));
	printf ("MY: %s\n", ft_strdup("dada ya, pelmeni norm tema ksta"));
}

int main(void)
{
	write_test();
	read_test();
	strlen_test();
	strcpy_test();
	strdup_test();
	return (0);
}