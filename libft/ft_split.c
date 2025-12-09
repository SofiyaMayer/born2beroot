/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:48 by someyer           #+#    #+#             */
/*   Updated: 2025/12/09 14:22:44 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t count_words(const char *s, char c)
{
    size_t i = 0;
    size_t count = 0;
    size_t in_word = 0;

    if (!s)
        return 0;
    while (s[i])
    {
        if (s[i] != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (s[i] == c)
            in_word = 0;
        i++;
    }
    return count;
}

char	*word_dup(char const *s, size_t len)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
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
	splitted = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitted)
		return (NULL);
	while (i < word_count)
	{
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
//     size_t i;
//     char **res;

//     char *tests[] = {
//         "   test this thingy  ",
//         "oneword",
//         "   ",
//         "",
//         "a b  c   d",
//         NULL
//     };

//     for (i = 0; tests[i] != NULL; i++)
//     {
//         printf("Test %zu: \"%s\"\n", i + 1, tests[i]);
//         res = ft_split(tests[i], ' ');

//         if (!res)
//         {
//             printf("ft_split returned NULL\n");
//             continue;
//         }

//         size_t j = 0;
//         while (res[j])
//         {
//             printf("  word[%zu]: \"%s\"\n", j, res[j]);
//             free(res[j]); // free each duplicated word
//             j++;
//         }
//         free(res); // free the array itself
//         printf("\n");
//     }

//     return 0;
// }