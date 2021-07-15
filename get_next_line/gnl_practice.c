/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:48:45 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/15 12:03:41 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>

int get_next_line(char **line)
{
	int i = 0;
	int r;
	char c;
	char *buffer;

	if(!(buffer = (char *)malloc(10000)))
		return (-1);
	while ((r = read(0, &c, 1)) && c != '\0' && c != '\n')
	{
		if (c != '\0' && c != '\n')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;

	return (r);
}

int main(void)
{
    int bytes;
    char *line;

    line = NULL;
    while ((bytes = get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s", line);
    free(line);
    line = NULL;
    return (0);
}