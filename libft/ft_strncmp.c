/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:43:38 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 15:42:36 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && (*s1 == *s2))
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

// int	main(void)
// {
// 	const char	*s1 = "abc\0\0";
// 	const char	*s2 = "abc\0e";

// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	printf("%d\n", strncmp(s1, s2, 6));
// }
