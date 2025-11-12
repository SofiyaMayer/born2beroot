/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:17:57 by someyer           #+#    #+#             */
/*   Updated: 2025/11/12 18:02:46 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_cpy;
	char		*dest_cpy;

	i = 0;
	src_cpy = src;
	dest_cpy = dest;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	str[10] = "Testik";

	memcpy(str + 3, str, 6);
	printf("%s", str);
}
