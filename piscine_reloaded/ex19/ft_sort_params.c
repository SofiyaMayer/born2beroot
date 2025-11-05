/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:27:28 by someyer           #+#    #+#             */
/*   Updated: 2025/11/05 17:36:11 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char character)
{
	write(1, &character, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

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
		}
		i++;
	}
	return (difference);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;
	char	**sorted;

	i = 1;
	sorted = argv;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_strcmp(sorted[i], sorted[i + 1]) > 0)
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
				i = 1;
			}
			else
				i++;
		}
		i = 1;
		while (i < argc - 1)
		{
			ft_putstr(sorted[i]);
			i++;
		}
	}
	return (0);
}
