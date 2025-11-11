/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:20:30 by someyer           #+#    #+#             */
/*   Updated: 2025/11/11 17:25:03 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*));

int	found_size(char **tab)
{
	return (sizeof(tab) / sizeof(tab[0]));
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	size;
	int	number;

	i = 0;
	number = 0;
	size = found_size(tab);
	while (i < size)
	{
		if (f(tab[i]) == 1)
			number++;
		i++;
	}
	return (number);
}
