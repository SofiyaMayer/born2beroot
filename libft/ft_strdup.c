/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:47:40 by someyer           #+#    #+#             */
/*   Updated: 2025/11/26 20:02:00 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char *ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (i < ft_strlen(s))
	{
		dup[i] = s[i];
		i++; 
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	*test;
// 	char	*result;
	
// 	test = "test";
// 	result = ft_strdup(test);
// 	printf("Custom: %s\n", ft_strdup(test));
// 	free(result);

// 	result = strdup(test);
// 	printf("Official: %s\n", strdup(test));
// 	free(result);
// }