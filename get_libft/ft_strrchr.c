/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:50:50 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/04 13:50:25 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*n;

	n = (char *)s;
	i = ft_strlen(n);
	if (n[i] == '\0' && (unsigned char)c == '\0')
		return (&n[i]);
	while (i > 0)
	{
		i--;
		if (n[i] == (unsigned char)c)
			return (&n[i]);
	}
	if (n[i] == '\0' && (unsigned char)c == '\0')
		return (&n[i]);
	return (0);
}
