/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:04:00 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 18:37:53 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
//     t_list *list = NULL;
//     t_list *a = ft_lstnew("World");
//     t_list *b = ft_lstnew("Hello");

//     ft_lstadd_front(&list, a); // list: World
//     ft_lstadd_front(&list, b); // list: Hello -> World

//     printf("%s -> %s\n", (char*)list->content, (char*)list->next->content);
// }
