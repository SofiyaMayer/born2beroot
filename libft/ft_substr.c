/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiemeyer <sofiemeyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:31:46 by sofiemeyer        #+#    #+#             */
/*   Updated: 2025/12/01 14:19:44 by sofiemeyer       ###   ########.fr       */
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
    substr = malloc(sizeof(char) * len + 1);
    if (!substr)
        return (NULL);
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}