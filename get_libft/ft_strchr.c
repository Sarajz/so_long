/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:40:52 by sarajime          #+#    #+#             */
/*   Updated: 2023/09/21 13:04:24 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*n;

	n = (char *)s;
	i = 0;
	if (c > 255)
		c = c -256;
	while ((n[i] != '\0') && (n[i] != (char)c))
		i++;
	if (n[i] == (char)c)
		return (&n[i]);
	else
		return (0);
}
