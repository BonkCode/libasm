#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "lorem.h"

int ft_write(int fd, char *str, int len);

void write_test()
{
	int fd;
	int ret;
	int len;

	fd = open("test.txt", O_WRONLY);
	printf("==============TESTING WRITE=============\n");
	printf("STDIN\nORIGINAL\n");
	ret = write(1, "Hello World!\n", 13);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(1, "Hello World!\n", 13);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	ret = write(-1, "Hello World!\n", 13);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(-1, "Hello World!\n", 13);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	ret = write(42, "Hello World!\n", 13);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(42, "Hello World!\n", 13);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	ret = write(1, "Hello World!\n", -5);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(1, "Hello World!\n", -5);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	ret = write(1, "", 0);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(1, "", 0);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	len = strlen(LOREM);
	ret = write(1, LOREM, len);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(1, LOREM, len);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
	printf ("----------------------\n");
	printf("STDIN\nERRNO CHECK\n");
	len = strlen(LOREM);
	ret = write(fd, "da", 2);
	printf("ORIGINAL WRITE RET: %i\n", ret);
	printf ("ORIG errno: %i\n", errno);
	errno = 0;
	ret = ft_write(fd, "da", 2);
	printf("MY WRITE RET: %i\n", ret);
	printf ("MY errno: %i\n", errno);
	errno = 0;
}

int main(void)
{
	write_test();
	return (0);
}