/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:14:37 by someyer           #+#    #+#             */
/*   Updated: 2025/11/26 19:55:28 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_cpy;
	const char	*s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	while (n > 0 && s1_cpy && (*s1_cpy == *s2_cpy))
	{
		n--;
		s1_cpy++;
		s2_cpy++;
	}
	if (n == 0)
		return (0);
	return (*s1_cpy - *s2_cpy);
}

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = "Test";
// 	test2 = "Test";
// 	printf("Custom: %d\n", ft_memcmp(test1, test2, 20));
// 	printf("Official: %d\n", memcmp(test1, test2, 20));
// }