#include "libftprintf.h"

int	main(void)
{
	int	x;

	x = ft_printf("Hello %s! Number: %d, Hex: %x, \
Pointer: %p, Char: %c, %%\n", "world", 42, 255, (void *)0x1234, 'A');
	printf("ft_printf returned: %d\n", x);
	printf("Hello %s! Number: %d, Hex: %x, Pointer: %p, \
Char: %c, %%\n", "world", 42, 255, (void *)0x1234, 'A');
	return (0);
}
