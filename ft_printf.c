/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:04:37 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/23 13:39:40 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_numlen(long long num, int base_len)
{
	int i = 1;
	while (num >= base_len)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

void ft_putnbr(long long num, int base_len, char *base)
{
	char c;
	if (num >= base_len)
		ft_putnbr(num / base_len, base_len, base);
	c = base[num % base_len];
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (*str++)  //est-ce que ca va être bon??
		i++;
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	char *base;
	long long num;
	int width = 0, prs = 0, prs_len = 0, ret = 0, negative = 0, zeros = 0, spaces = 0, base_len = 0, len = 0;
	va_start(list, format);
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			width = 0, prs = 0, prs_len = 0, negative = 0, zeros = 0, spaces = 0, base_len = 0, len = 0;
			while(*format >= '0' && *format <= '9')
			{
				width = width * 10 + (*format - '0');
				format++;
			}
			if (*format == '.')
			{
				prs = 1;
				format++;
				while (*format >= '0' && *format <= '9')
				{
					prs_len = prs_len * 10 + (*format - '0');
					format++;
				}
			}
			if (*format == 's')
			{
				str = va_arg(list, char *);
				len = ft_strlen(str);	
			}
			if (*format == 'd')
			{
				num = va_arg(list, int);
				if (num < 0)
				{
					num = -num;
					negative = 1;
				}
				base = "0123456789";
				base_len = 10;
				len = ft_numlen(num, base_len);
			}
			if (*format == 'x')
			{
				num = va_arg(list, unsigned int);
				base = "0123456789abcdef";
				base_len = 16;
				len = ft_numlen(num, base_len);
			}
			if (prs)
			{
				if (*format == 's' && prs_len < len)
					len = prs_len;
				if (*format != 's' && prs_len > len)
					zeros = prs_len - len;
				if (prs_len == 0 && (*format == 's' || !num))
					len = 0;
			}
			spaces = width - len - negative - zeros;
			while (spaces-- > 0)
			{
				write (1, " ", 1);
				ret++;
			}
			if (negative == 1)
			{
				write (1, "-", 1);
				ret++;
			}
			while (zeros-- > 0)
			{
				write (1, "0", 1);
				ret++;
			}
			if (*format == 's')
				write(1, str, len);
			else if (len > 0)
				ft_putnbr(num, base_len, base);
			ret += len;
		}
		else
		{
			write (1, &*format, 1);
			ret++;
		}
		format++;
	}
	va_end(list);
	return (ret);
}

int main()
{
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return 0;
}
