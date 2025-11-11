/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiemeyer <sofiemeyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:20:13 by sofiemeyer        #+#    #+#             */
/*   Updated: 2025/11/06 23:00:27 by sofiemeyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int *ft_range(int min, int max)
{
    int i;
    int length;
    int *array;

    length = max - min;
    array = (int *)malloc(sizeof(int) * length);
    if (!array || min >= max)
        return (NULL);
    i = 0;
    while(i < length)
    {
        array[i] = i;
        i++;
    }
}