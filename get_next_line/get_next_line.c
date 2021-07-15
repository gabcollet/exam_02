/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:07:55 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/14 15:08:10 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line)					//prend l'int du file descriptor + le char ** de la ligne
{
	int		i;
	int		l = 1;
	int		r = 0;
	char	c;
	char	*tmp;

	if (!(*line = malloc(l))) 							//malloc un espace de 1 pour la ligne
		return (-1);									//si fail retourne -1
	(*line)[0] = 0;										//remettre la position 0 du pointeur comme 0
	while ((r = read(3, &c, 1)) && c != '\n')			//pendant qu'il y a dequoi à lire sur le fd 3 un buffer de 1 jusqu'à c != \n
	{													//met le char lu dans l'adresse de c.
		if (!(tmp = malloc(l)))								//malloc un espace de 1 pour le tmp
		{
			free(*line);									//si ca fail free la ligne et retourne -1
			return (-1);
		}
		i = 0;												//remettre i à 0
		while (i < l-1)										//pendant que i < l-1 incrémente i
		{
			tmp[i] = (*line)[i];							//position de i dans tmp devient la position de i dans *line
			i++;											//incrémente le i
		}
		tmp[i] = c;											//tmp prend le char c du read
		tmp[i + 1] = 0;										//tmp + 1 devient 0
		free(*line);										//free la line
		*line = tmp;										//*line prend l'adresse de tmp qui est malloc déjà
		l++;												//incrémente l
	}													//recommence
	return (r);											//retourne 1 si un char a été lu sinon 0
}

/* int main(void)
{
	int r;
	int fd;
	char *line;
	

	line = NULL;
	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	printf("==================================================\n");
	while ((r = get_next_line(&line)) > 0)
	{
		printf ("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	printf("==================================================\n");
} */