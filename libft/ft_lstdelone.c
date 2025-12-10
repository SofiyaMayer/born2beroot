/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:14:25 by someyer           #+#    #+#             */
/*   Updated: 2025/12/10 18:43:50 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// void del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *node = ft_lstnew(ft_strdup("hello"));

//     ft_lstdelone(node, del);

//     printf("Node deleted (if no crash, than gut)\n");
// }
