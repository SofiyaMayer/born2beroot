/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:22:08 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 18:40:39 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
//     t_list *list = ft_lstnew(ft_strdup("one"));
//     t_list *a = ft_lstnew(ft_strdup("two"));
//     t_list *b = ft_lstnew(ft_strdup("three"));

//     list->next = a;
//     a->next = b;

//     ft_lstclear(&list, del);

//     if (list == NULL)
//         printf("List cleared!\n");
// }