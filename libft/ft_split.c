/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:48 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 20:09:16 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	*word_dup(char const *s, size_t len)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(len + 1);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char **ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	i;
	size_t	word_len;
	size_t	word_count;
	
	i = 0;
	word_len = 0;
	word_count = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	while (i < word_count)
	{
		printf("%zu\n", i);
		while (*s == c)
			s++;

		while (s[word_len] != c && s[word_len] != '\0') 
			word_len++;
		splitted[i] = word_dup(s, word_len);
		s += word_len;
		word_len = 0;
		i++;
	}
	splitted[i] = 0;
	return (splitted);
}

// int main(void)
// {
// 	size_t	i;
// 	char	**res;
// 	char	*test = "   test this thingy";
	
// 	i = 0;
// 	res = ft_split(test, ' ');
// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// }