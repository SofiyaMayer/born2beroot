/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:59:22 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 16:05:14 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	char_len(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*alloc_string(size_t len)
{
	char	*str;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		start;
	int		len;
	int		digit;
	char	*str;

	start = 0;
	len = char_len(n);
	str = alloc_string(len);
	if (n == -2147483648)
		return (ft_strlcpy(str, "-2147483648", len + 1), str);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		start = 1;
	}
	str[len] = '\0';
	while (len > start)
	{
		digit = n % 10 + '0';
		str[--len] = digit;
		n /= 10;
	}
	return (str);
}

// int main(void)
// {
// 	int		i;
// 	int		number;
// 	char	*result;
// 	i = 0;
// 	number = INT_MIN;
// 	result = ft_itoa(number);
// 	printf("result: %s\n", result);
// 	free(result);
// }
