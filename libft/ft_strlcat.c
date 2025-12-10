/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:32:08 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 17:35:46 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	else
	{
		while (i < (size - dst_len - 1) && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

// int main(void)
// {
// 	char	*dst = "Concatenate me! ";
// 	char	*src = "Meow!";

// 	printf("Custom: %zu\n", ft_strlcat(dst, src, 0));
// 	printf("Custom: %zu\n", strlcat(dst, src, 0));
// }
