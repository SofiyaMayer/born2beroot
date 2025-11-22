/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:58:35 by someyer           #+#    #+#             */
/*   Updated: 2025/11/22 12:57:24 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	int	upcase_diff;

	upcase_diff = 'A' - 'a';
	if (c >= 'a' && c <= 'z')
		c = c + upcase_diff;
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'g';
// 	c = ft_toupper(c);
// 	printf("%c", c);
// }