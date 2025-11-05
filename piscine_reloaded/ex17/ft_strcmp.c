/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:01:24 by someyer           #+#    #+#             */
/*   Updated: 2025/11/05 15:18:07 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = *s1 - *s2;
	if (s1 == s2)
		return (res);
	else
		return (res);
}

// int	main(void)
// {
// 	printf("%d", ft_strcmp("c", "a"));
// }

