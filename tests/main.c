#include "../headers/libasm.h"

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

void strcmp_test()
{
	printf("==============TESTING STRCMP=============\n");
	printf ("MY: %i\n", ft_strcmp("abc", "abb"));
	printf ("ORIG: %i\n", strcmp("abc", "abb"));
	printf ("MY: %i\n", ft_strcmp("ab", "abb"));
	printf ("ORIG: %i\n", strcmp("ab", "abb"));
	printf ("MY: %i\n", ft_strcmp("abc", "ab"));
	printf ("ORIG: %i\n", strcmp("abc", "ab"));
	printf ("MY: %i\n", ft_strcmp("abc", "abc"));
	printf ("ORIG: %i\n", strcmp("abc", "abc"));
	printf ("MY: %i\n", ft_strcmp(LOREM, LOREM));
	printf ("ORIG: %i\n", strcmp(LOREM, LOREM));
	printf ("MY: %i\n", ft_strcmp("abc", "abQ"));
	printf ("ORIG: %i\n", strcmp("abc", "abQ"));
	printf ("MY: %i\n", ft_strcmp("", ""));
	printf ("ORIG: %i\n", strcmp("", ""));
	printf ("MY: %i\n", ft_strcmp("abcqasvdsvdsvsdvdsvds", "qhthtrth3"));
	printf ("ORIG: %i\n", strcmp("abcqasvdsvdsvsdvdsvds", "qhthtrth3"));
}

void strdup_test()
{
	char *ptr;
	char *dst;

	dst = malloc(32);
	printf("==============TESTING STRDUP=============\n");
	printf ("ORIG: %s\n", strdup("dada ya, pelmeni norm tema ksta"));
	printf ("MY: %s\n", ft_strdup("dada ya, pelmeni norm tema ksta"));
	printf ("ORIG: %s\n", strdup(""));
	printf ("MY: %s\n", ft_strdup(""));
	printf ("ORIG: %s\n", strdup("q"));
	printf ("MY: %s\n", ft_strdup("q"));
	printf ("ORIG: %s\n", strdup(LOREM));
	printf ("MY: %s\n", ft_strdup(LOREM));
}

int main(void)
{
	write_test();
	read_test();
	strlen_test();
	strcpy_test();
	strdup_test();
	strcmp_test();
	return (0);
}