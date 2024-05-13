/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:52:39 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/09 10:46:04 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		if (num == -2147483648)
			return (11);
		if (num < 0)
		{
			count++;
			num *= -1;
		}
		while (num > 0)
		{
			num = num / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	new_n;

	i = ft_count_digit(n);
	new_n = n;
	str = (char *)malloc (i + 1);
	if (str == NULL)
		return (NULL);
	if (new_n == 0)
		str[0] = '0';
	str[i--] = '\0';
	if (new_n < 0)
	{
		str[0] = '-';
		new_n *= -1;
	}
	while (new_n > 0)
	{
		str[i--] = (new_n % 10) + '0';
		new_n = new_n / 10;
	}
	return (str);
}
