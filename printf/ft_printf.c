/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:14:27 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/15 15:52:50 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

//classique fonction pour compter la len
int ft_strlen(char *str)
{
	int i = 0;
	
	while (*str++)
		i++;
	return(i);
}

//fonction pour compter la len d'un int en fonction de la longeur de la base spécifié
int ft_numlen(long long num, int base_len)
{
	unsigned int len = 1;

	while(num >= base_len)
	{
		len++;
		num /= base_len;
	}
	return (len);
}

//C'est ici que la magie de la conversion s'oppere pour les int
void ft_putnbr(long long num, int base_len, char *base)
{
	char c;
//la fonction utilise la récursion pour diviser le num par 
//la base jusqu'à ce qu'il soit convertissable
	if(num >= base_len) 
		ft_putnbr(num/ base_len, base_len, base);
	c = base[(num % base_len)];
	write(1, &c, 1);
}

//Le coeur de la machine qui fait le check des arguments
int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	char *base;
	long long num = 0;
	int width = 0, prs = 0, prs_len = 0, len = 0, base_len = 0, 
		negative = 0, zeros = 0, spaces = 0, ret = 0;

	va_start(list, format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			width = 0, prs = 0, prs_len = 0, len = 0, base_len = 0, 
			negative = 0, zeros = 0, spaces = 0;
		//si en commencant la str est un chiffre, calcul la width
			while(*format >= '0' && *format <= '9') 
			{
				width = width * 10 + (*format - '0');
				format++;
			}
		//si il y a un point comme la width mais dans la précision
			if(*format == '.') 
			{
				prs = 1;
				format++;
				while(*format >= '0' && *format <= '9')
				{
					prs_len = prs_len * 10 + (*format - '0');
					format++;
				}
			}
		//prend l'arg s et calcul ca lenght
			if(*format == 's') 
			{
				str =  va_arg(list, char *);
				if(!str)
					str = "(null)";
				len = ft_strlen(str);
			}
		//prend l'arg d, le remet positif et calcul ca lenght
			else if (*format == 'd') 
			{
				base_len = 10;
				base = "0123456789";
				num = va_arg(list, int);
				if (num < 0)
				{
					negative = 1;
					num = -num;
				}
				len = ft_numlen(num, base_len);
			}
		//prend l'arg x et calcul la lenght
			else if(*format == 'x')
			{
				base_len = 16;
				base = "0123456789abcdef";
				num = va_arg(list, unsigned int);
				len = ft_numlen(num, base_len);
			}
		//calcul la précision selon sa longeur et la longeur de l'arg. 
		//Si c'est un s et que la précision est plus petite, elle va prendre
		//la lenght de la précision
		//Sinon elle va calculer les zéro pour un int selon la précision - la longeur de l'int.
		//Si il n'y a pas de précision et que c'est un s ou qu'il n'y a 
		//pas de num (0) la lenght va être de 0.
			if(prs)
			{
				if (prs_len > len && *format != 's')
					zeros = prs_len - len;
				if (prs_len < len && *format == 's')
					len = prs_len;
				if (!prs_len && (*format == 's' || !num))
					len = 0;
			}
		//ici le calcul de l'espace à imprimer
			spaces = width - zeros - len - negative;
		
		//ecrire les espaces, le moin et les zeros s'il y a lieu	
			while(spaces-- > 0)
			{
				write(1, " ", 1);
				ret++;
			}
			if (negative)
			{
				write(1, "-", 1);
				ret++;
			}
			while(zeros-- > 0)
			{
				write(1, "0", 1);
				ret++;
			}
		//ecrire la string sinon passe l'int dans le putnbr avec la base
			if(*format == 's')
				write(1, str, len);
			else if(len)
				ft_putnbr(num, base_len, base);
			ret += len;
		}
		//si c'est pas un arg écrire le texte normal à l'adresse du ptr format
		else
		{
			write(1, &*format, 1);
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