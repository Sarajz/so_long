/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:05:56 by sarajime          #+#    #+#             */
/*   Updated: 2024/04/23 19:05:18 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_strjoin(char const *s1, char const *s2, int num_bytes)
{
	char			*s3;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
	{
		s1 = malloc(sizeof (char));
		if (!s1)
			return (NULL);
		((char *)s1)[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(get_strlen(s1) + num_bytes + 1);
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free ((char *) s1);
	return (s3);
}

char	*get_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c > 255)
		c = c % 256;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (&s[i]);
	else
		return (0);
}
