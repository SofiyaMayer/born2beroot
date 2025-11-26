/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:18:17 by someyer           #+#    #+#             */
/*   Updated: 2025/11/26 17:14:03 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_cpy;

	s_cpy = s;
	while (n > 0 && s_cpy)
	{
		n--;
		if (*s_cpy == c)
			return ((void *)s_cpy);
		s_cpy++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*test;
// 	char	*ptr;
// 	char	*ptr2;

// 	test = "Test";
// 	printf("%s\n", (char *)ft_memchr(test, 's', 8));
// 	printf("%s\n", (char *)memchr(test, 's', 8));
// }