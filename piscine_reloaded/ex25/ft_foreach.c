/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:19:17 by someyer           #+#    #+#             */
/*   Updated: 2025/11/11 17:19:46 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

// void	ft_putnbr(int nb);
// int		find_length(int nb);

// int	find_length(int nb)
// {
// 	int	len;

// 	len = 1;
// 	while (nb / 10 != 0)
// 	{
// 		nb /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// void	ft_putnbr(int nb)
// {
// 	int		i;
// 	int		len;
// 	char	array[10];

// 	i = 0;
// 	len = find_length(nb);
// 	if (nb == -2147483648)
// 	{
// 		write (1, "-2147483648", 11);
// 		return ;
// 	}
// 	else if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb *= -1;
// 	}
// 	while (i < len)
// 	{
// 		array[len - i - 1] = '0' + nb % 10;
// 		nb /= 10;
// 		i++;
// 	}
// 	write (1, array, len);
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// int main(void)
// {
//     int tab[5] = {0,2,3,4,5};
//     ft_foreach(tab, 5, &ft_putnbr);
// }