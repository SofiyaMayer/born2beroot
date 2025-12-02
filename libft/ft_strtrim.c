/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:41 by someyer           #+#    #+#             */
/*   Updated: 2025/12/02 17:56:10 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	i;
	
	start = 0;
	end = ft_strlen(s1);
	while(s1[start] && ft_strchr(set, s1[start]))
		start++;
	while(end > start && ft_strchr(set, s1[end - 1]))
		end--;
	printf("start: %zu end: %zu\n", start, end);
	trimmed = malloc(end - start + 1);
	while (start < end)
	{
		trimmed[i] = s1[start];
		start++;
		i++;
	}
	return(trimmed);
}

// int main(void)
// {
// 	const char	*test = "--ab--ab Test --ab--ab";
// 	char	*trimmed;

// 	trimmed = ft_strtrim(test, "--ab");
// 	printf("%s\n", trimmed);
// }