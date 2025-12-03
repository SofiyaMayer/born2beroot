/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:31:46 by sofiemeyer        #+#    #+#             */
/*   Updated: 2025/12/03 20:16:41 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, 
    size_t len)
{
    size_t  i;
    char    *substr;
    
    i = 0;
	if (len <= 0)
		return (NULL);
    substr = malloc(sizeof(char) * len + 1);
    if (!substr)
        return (NULL);
    while (i < len && s[i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}