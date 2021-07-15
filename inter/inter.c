/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:35:11 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/15 09:55:27 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(0, &c, 1);
}

int ft_strlen(char *a)
{
    int i = 0;
    while (a[i])
        i++;
    return (i);
} 

void inter(char *a, char *b)
{
    int x = 0;
    int i = 0;
    int z = 0;
    int len = ft_strlen(a);
    
    char tmp[len];
    while (a[x])
    {
        int y = 0;
        while (b[y])
        {
            if (a[x] == b[y])
            {
                z = 0;
                while (tmp[z])
                {
                    if(a[x] == tmp[z])
                        break;
                    if(tmp[z+1] == '\0')
                    {
                        tmp[i] = a[x];
                        i++;
                        ft_putchar(a[x]);
                    }
                    z++;
                }
            }
            y++;
        }
        x++;    
    }
    ft_putchar('\n');
}

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return (-1);
    }
    char *a = argv[1];
    char *b = argv[2];
    inter(a, b);
    return 0;
}
