/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:29:23 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/06 11:49:07 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int get_next_line(char **line)
{
	char *buffer;
	int i = 0;
	int r = 0;
	char c;

	if (!(buffer = (char *)malloc(10000)))
		return (-1);
	while ((r = read(0, &c, 1)) && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}

int main (void)
{
	char *line;
	int ret;

	line = NULL;
	while((ret = get_next_line(&line)) > 0)
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
