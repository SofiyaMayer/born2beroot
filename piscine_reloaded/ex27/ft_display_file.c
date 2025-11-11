/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:21:47 by someyer           #+#    #+#             */
/*   Updated: 2025/11/11 17:24:17 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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
}

int	main(int argc, char **argv)
{
	int		fd;
	char	data[512];

	if (argc == 1)
		ft_putstr("File name missing.");
	if (argc > 2)
		ft_putstr("Too many arguments.");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.");
			return (0);
		}
		while (read(fd, &data, 512) != 0)
		{
			ft_putstr(data);
		}
		close(fd);
	}
	return (0);
}
