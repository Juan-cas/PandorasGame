/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:23 by juan-cas          #+#    #+#             */
/*   Updated: 2023/12/21 16:49:29 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*append(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	s3 = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!s3)
		return (free(s1), s1 = NULL, free(s2), s2 = NULL, NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (s3);
}

static char	*reader(int fd, char *saver)
{
	char	*storage;
	int		bytesread;

	bytesread = BUFFER_SIZE;
	storage = NULL;
	while (bytesread == BUFFER_SIZE)
	{
		storage = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!storage)
			exit(1);
		bytesread = read(fd, storage, BUFFER_SIZE);
		if (bytesread < 0)
			exit(1);
		if (bytesread > 0)
		{
			saver = append(saver, storage);
			if (!saver)
				exit(1);
		}
		if (bytesread == 0)
			exit(1);
	}
	return (saver);
}

char	*get_next_line(int fd)
{
	char	*saver = NULL;

	if (fd < 0 || read(fd, NULL, 0))
	{
		perror("issues with the file you are trying to open\n");
		exit(1);
	}
	saver = reader(fd, saver);
	if (!saver)
		exit(1);
	return (saver);
}
