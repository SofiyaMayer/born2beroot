/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:42:17 by someyer           #+#    #+#             */
/*   Updated: 2025/11/05 13:45:31 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char character)
{
	write(1, &character, 1);
}

void	ft_print_numbers(void)
{
	int	digit;

	digit = '0';
	while (digit <= '9')
	{
		ft_putchar(digit);
		digit++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// }
