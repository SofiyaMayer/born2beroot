/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:27 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 14:17:18 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

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
	if (*little == '\0')
		return (big_cpy);
	while (len > 0 && *big_cpy)
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
//     const char *haystack = "abcdefghi";

//     printf("Test: haystack=\"abcdefghi\", needle=\"cd\", n=8\n");
//     printf("ft_strnstr: %p\n", ft_strnstr(haystack, "cd", -1));
//     printf("strnstr:    %p\n", strnstr(haystack, "cd", -1));

//     return 0;
// }