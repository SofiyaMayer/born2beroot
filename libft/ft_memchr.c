/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:18:17 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 21:11:01 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cpy;

	s_cpy = (char *)s;
	while (n > 0 && s_cpy)
	{
		n--;
		if (*s_cpy == (char)c)
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