/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:07:27 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 21:42:19 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *)s;
	while (*s_cpy)
	{
		if (*s_cpy == (char)c)
			return (s_cpy);
		s_cpy++;
	}
	if (*s_cpy == (char)c)
		return (s_cpy);
	return (NULL);
}

// int	main(void)
// {
// 	char	*test;
// 	char	*ptr;

// 	test = "Tet";
// 	ptr = ft_strchr(test, 0);
// 	printf("Custom: %s", ptr);
// 	printf("Official: %s\n", strchr(test, 0));
// }