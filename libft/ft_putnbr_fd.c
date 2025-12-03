/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:09:19 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 19:33:21 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	num_len(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	char	array[12];

	i = 0;
	len = num_len(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (i < len)
	{
		array[len - i - 1] = '0' + n % 10;
		n /= 10;
		i++;
	}
	write (fd, array, len);
}