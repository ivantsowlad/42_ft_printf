#include "./libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;
	char	*bases[3];

	bases[0] = "0123456789";
	bases[1] = "0123456789abcdef";
	bases[2] = "0123456789ABCDEF";
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed += ft_format(format[i], &args, bases);
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
