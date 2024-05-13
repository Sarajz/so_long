/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:14:50 by sarajime          #+#    #+#             */
/*   Updated: 2023/09/14 14:30:27 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*n;

	n = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		n[i] = (unsigned char)c;
		i++;
	}
	return ((void *)n);
}
