/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:01:24 by someyer           #+#    #+#             */
/*   Updated: 2025/11/11 17:26:33 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	difference;

	difference = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			difference = s1[i] - s2[i];
			return (difference);
		}
		i++;
	}
	return (difference);
}

// int	main(void)
// {
// 	printf("%d", ft_strcmp("c", "a"));
// }
