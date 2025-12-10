/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:43:12 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 18:47:59 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew((*f)(lst->content));
	if (!node)
	{
		ft_lstclear(&node, del);
		return (NULL);
	}
	head = node;
	while (lst->next)
	{
		lst = lst->next;
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
	}
	return (head);
}

// void *duplicate(void *content)
// {
//     return (ft_strdup((char *)content));
// }

// void del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *a = ft_lstnew(ft_strdup("one"));
//     t_list *b = ft_lstnew(ft_strdup("two"));
//     t_list *c = ft_lstnew(ft_strdup("three"));
//     a->next = b;
//     b->next = c;

//     t_list *mapped = ft_lstmap(a, duplicate, del);

//     printf("%s -> %s -> %s\n",
//         (char*)mapped->content,
//         (char*)mapped->next->content,
//         (char*)mapped->next->next->content);

//     ft_lstclear(&a, del);
//     ft_lstclear(&mapped, del);
// }
