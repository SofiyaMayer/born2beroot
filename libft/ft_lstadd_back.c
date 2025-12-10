/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:38:35 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 18:36:22 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
	new->next = NULL;
}

// int main(void)
// {
//     t_list *list = NULL;
//     t_list *a = ft_lstnew("Hello");
//     t_list *b = ft_lstnew("World");

//     ft_lstadd_back(&list, a);
//     ft_lstadd_back(&list, b);

//     // Print result
//     printf("%s -> %s\n", (char*)list->content, (char*)list->next->content);
// }