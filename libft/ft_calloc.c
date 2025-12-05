/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:02:58 by someyer           #+#    #+#             */
/*   Updated: 2025/12/05 18:25:37 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	char			*array;
	char			*alloc;
	unsigned long	total_size;
	i = 0;
	if (nmemb <= 0 || size <= 0)
	{
		alloc = malloc(1);
		return (alloc);
	}
	total_size = (unsigned long)(nmemb * size);
	if (nmemb > 65355 || size > 65355)
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