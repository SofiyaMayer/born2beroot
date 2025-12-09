/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:14:47 by someyer           #+#    #+#             */
/*   Updated: 2025/12/09 12:38:49 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}