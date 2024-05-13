/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:31:54 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/10 12:12:01 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	digit = 0;
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n < 10 && n >= 0)
		ft_putchar_fd (n + '0', fd);
	if (n >= 10)
	{	
		digit = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(digit + '0', fd);
	}
}
