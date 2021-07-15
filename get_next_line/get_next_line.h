/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:07:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/14 15:08:46 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h> //read
#include <stdlib.h> //malloc, free

#include <stdio.h> //printf dans le main()
#include <fcntl.h> //open dans le main()

int get_next_line(char **line);

#endif