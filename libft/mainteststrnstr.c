#include <stdio.h>
#include "libft.h"
#include <string.h>

int main(void)
{
	const char *haystack1;
	const char *needle1;
	unsigned long len2;
	haystack1 = "abcdef";
	needle1 = "abcdefghijklmnop";
	len2 = 6;
	printf("%s\n%s\n%lu\n%s\n%s\n", haystack1, needle1, len2, ft_strnstr(haystack1, needle1, len2), strnstr(haystack1, needle1, len2));
	return (0);
}
