#include "./libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	len_base;
	int	count;

	len_base = 0;
	count = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= (unsigned long)len_base)
		count += ft_putnbr_base(nbr / len_base, base);
	count += ft_putchar(base[nbr % len_base]);
	return (count);
}

int	ft_format(char spec, va_list *args, char **bases)
{
	unsigned long	ptr;

	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (spec == 'p')
	{
		ptr = va_arg(*args, unsigned long);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_putnbr_base((unsigned long)ptr, bases[1]));
	}
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (spec == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[0]));
	else if (spec == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[1]));
	else if (spec == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[2]));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}
