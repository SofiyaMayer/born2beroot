/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:10:56 by someyer           #+#    #+#             */
/*   Updated: 2025/11/12 21:29:12 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	size_t		len;

	len = ft_strlen(s);
	while (len-- >= 0)
	{
		if (s[len] == c)
		{
			while (*s != s[len])
				s++;
		}
	}
	return (s);
}

int	main(void)
{
	char		*test = "Test";
	char	*ptr;

	ptr = ft_strrchr(test, 's');
	printf("%s", ptr); 
}