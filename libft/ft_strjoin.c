/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiemeyer <sofiemeyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:20:55 by sofiemeyer        #+#    #+#             */
/*   Updated: 2025/12/01 14:55:06 by sofiemeyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  total_len;
    char    *result;
    
    total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
    result = malloc(sizeof(char) * total_len);
    if (!result)
        return (NULL);
    ft_strlcpy(result, s1, total_len);
    ft_strlcat(result, s2, total_len);
    return (result);
}