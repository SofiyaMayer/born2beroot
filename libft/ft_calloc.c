/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:02:58 by someyer           #+#    #+#             */
/*   Updated: 2025/12/03 20:08:47 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*array;
	
	i = 0;
	if (nmemb == 0 || size <= 0)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_memset(array, 0, nmemb * size);
	return (array);
}

// int main(void)
// {
//     int *arr = ft_calloc(0, sizeof(int));
// 	int *arr2 = calloc(0, sizeof(int));

// 	printf("arr: %p\narr2: %p\n", arr, arr2);
	
//     //for (int i = 0; i < 5; i++)
//     //    printf("%d ", arr[i]);
//     printf("\n");
// 	for (int i = 0; i < 5; i++)
//         printf("%d ", arr2[i]);
//     printf("\n");
// 	free(arr);
// 	free(arr2);
// }