/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:28:52 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:29:33 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_putchar(const char c)
{
	write (1, &c, 1);
	return (1);
}

static size_t	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		++i;
	}
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	char			ch;
	unsigned int	i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
		{
			return ((char *)(s + i));
		}
		++i;
	}
	if (s[i] == ch)
	{
		return ((char *)(s + i));
	}	
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count;
	char	*specifiers;

	va_start(ap, str);
	i = 0;
	count = 0;
	specifiers = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(specifiers, str[i + 1]))
		{
			count += print_spf(str[i + 1], ap);
			++i;
		}
		else
			count += ft_putchar(str[i]);
		++i;
	}
	va_end(ap);
	return (count);
}

size_t	print_spf(const char ch, va_list ap)
{
	size_t	count;
	char	*lower_hex;
	char	*upper_hex;

	count = 0;
	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (ch == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (ch == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (ch == 'd' || ch == 'i')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789", 10, ch);
	else if (ch == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", 10, ch);
	else if (ch == '%')
		count += ft_putchar('%');
	else if (ch == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), lower_hex, 16, ch);
	else if (ch == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), upper_hex, 16, ch);
	else if (ch == 'p')
		count += ft_putnbr_base(va_arg(ap, long int), lower_hex, 16, ch);
	return (count);
}
