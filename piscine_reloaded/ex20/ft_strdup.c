/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiemeyer <sofiemeyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:54:28 by sofiemeyer        #+#    #+#             */
/*   Updated: 2025/11/06 22:59:54 by sofiemeyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char *ft_strdup(char *src)
{
    int     i;
    char    *duplicate;

    i = 0;
    duplicate = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!duplicate)
        return (NULL);
    while (src[i] != '\0')
    {
        duplicate[i] = src[i];
        i++;
    }
    duplicate[i] = '\0';
    return (duplicate);
}

// int main(void)
// {
//     char *src = "Hello World!";
//     char *duplicate;

//     duplicate = ft_strdup(src);
//     printf("%s", duplicate);
//     free(duplicate)
// }