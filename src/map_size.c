/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:03:02 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/15 16:54:44 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	n_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	size_ok(int fd)
{
	char	*c;
	int		i;
	int		temp;

	if (fd < 0)
		ft_exit("Fd is empty");
	c = get_next_line(fd);
	i = n_strlen(c);
	temp = i;
	free(c);
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		i = n_strlen(c);
		if (temp != i)
			return (0);
		free(c);
	}
	return (1);
}

int	size_x(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
		i++;
	if (line[i] == '\n')
		i--;
	return (i);
}

int	size_y(char **line)
{
	int	i;

	i = 0;
	while (*line)
	{
		i++;
		line++;
	}
	return (i);
}
