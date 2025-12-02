/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:48 by someyer           #+#    #+#             */
/*   Updated: 2025/12/02 18:32:11 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	count_words(char const *s)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		count++;
		while (s[i] != ' ' && s[i])
			i++;
	}
	return (count);
}

char	*word_dup(char *s, size_t start, size_t end)
{
	char	*dup;
	size_t	size;

	size = end - start;
	dup = malloc(size + 1);
	while (start < end)
	{
		dup[start] = s[start];
		start++;
	}
	return (dup);
}

char **ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	i;
	size_t	len;
	
	i = 0;
	len = count_words(s);
	splitted = (char **)malloc(len + 1);
	while (s[i] != c && s[i])
	{
	}
	return (splitted);
}

int main(void)
{
	size_t	i;
	char	**res;
	char	*test = "  test this   thingy";
	printf("words: %zu\n", count_words(test));
	
	i = 0;
	while (res[i] != 0)
	{
		printf("%s\n", res[i]);
		i++;
	}
}