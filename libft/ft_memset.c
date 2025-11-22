/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:07:56 by someyer           #+#    #+#             */
/*   Updated: 2025/11/22 12:56:59 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (s);
}
