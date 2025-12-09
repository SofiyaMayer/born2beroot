/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:31:22 by someyer           #+#    #+#             */
/*   Updated: 2025/12/09 12:42:17 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

t_list *ft_lstlast(t_list *lst)
{	
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}