/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:03:46 by someyer           #+#    #+#             */
/*   Updated: 2025/11/12 21:06:55 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	int	lowcase_diff;

	lowcase_diff = 'a' - 'A';
	if (c >= 'A' && c <= 'Z')
		c = c + lowcase_diff;
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'G';
// 	c = ft_tolower(c);
// 	printf("%c", c);
// }