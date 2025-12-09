/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:27 by someyer           #+#    #+#             */
/*   Updated: 2025/12/09 14:50:37 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"


// "We are looking for a substring"
// "for a substring"

// 1) Needed to find for if len is long enough,
// 2) check if it's a substring, if not, then iterate next

int	is_same(const char *s1, const char *substr)
{
	while (*substr && *s1 && (*s1 == *substr))
	{
		s1++;
		substr++;
	}
	return (*substr == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cpy;

	big_cpy = (char *)big;
	if (len > (size_t)ft_strlen(big))
		return (NULL);
	while (len > 0)
	{
		len--;
		if (is_same(big_cpy, little) == 1)
			return ((char *)big_cpy);
		big_cpy++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char	*test1;
// 	const char	*test2;

// 	test1 = "We are looking for a substring";
// 	test2 = "";

// 	printf("Custom: %s\n", ft_strnstr(test1, test2, 20));
// 	printf("Official: %s\n", strnstr(test1, test2, 20));
// }