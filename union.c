/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:16:40 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/23 11:29:11 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int arr[256];
	int i = 0;

	while (i < 256)
	{
		arr[i] = 0;
		i++;
	}
	if (ac == 3)
	{
		while (*av[1])
		{
			if(arr[(int)*av[1]] == 0)
			{
				arr[(int)*av[1]] = 1;
				write (1, av[1], 1);
			}
			av[1]++;
		}
		while (*av[2])
        {
            if(arr[(int)*av[2]] == 0)
            {
                arr[(int)*av[2]] = 1;
                write (1, av[2], 1);
            }
			av[2]++;
        }
	}
	write(1, "\n", 1);
	return (0);
}
