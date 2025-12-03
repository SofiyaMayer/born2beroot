/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:08:30 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 19:39:37 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_cpy;
	const char	*src_cpy;

	i = 0;
	src_cpy = src;
	dest_cpy = dest;
	if (dest < src)
	{
		while (i++ < n)
			dest_cpy[i] = src_cpy[i];
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_cpy[i] = src_cpy[i];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[10] = "Testik";
// 	char	str2[10] = "Testik";	

// 	ft_memmove(str1 + 2, str1, 7);
// 	printf("\n%s\n", str1);
// 	memmove(str2 + 2, str2, 7);
// 	printf("%s", str2);
// }
