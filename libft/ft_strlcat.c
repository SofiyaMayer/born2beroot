/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:32:08 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 19:58:27 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total_len;

	i = 0;
	total_len = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (total_len);
	else
	{
		while (i < (size - ft_strlen(dst) + 1) && src[i] != '\0')
		{
			dst[ft_strlen(dst) + i] = src[i];
			i++;
		}
		dst[ft_strlen(dst) + i] = '\0';
	}
	return (total_len);
}
