/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:58:27 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/15 10:42:01 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *b)
{
	int i;
	while(b[i])
		i++;
	return(i);
}

void ft_union(char *a, char *b)
{
	int i = 0;
	int x = 0;
	int z;
	int len = ft_strlen(b);
	char tmp[len];
	
	while(a[x])
	{	
		z = 0;
		while (tmp[z])
		{
			if(a[x] == tmp[z])
				break;
			if(tmp[z+1] == '\0')
			{
				tmp[i] = a[x];
				ft_putchar(tmp[i]);
				i++;
			}
			z++;	
		}
		x++;
	}
	x = 0;
	while(b[x])
	{	
		z = 0;
		while (tmp[z])
		{
			if(b[x] == tmp[z])
				break;
			if(tmp[z+1] == '\0')
			{
				tmp[i] = b[x];
				ft_putchar(tmp[i]);
				i++;
			}
			z++;	
		}
		x++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (-1);
	}
	char *a = argv[1];
	char *b = argv[2];
	ft_union(a, b);
	return (0);
}