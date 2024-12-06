/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:11 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 11:29:59 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*content;

	if (f == NULL || del == NULL || lst == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		content = lst->content;
		tmp = ft_lstnew(f(content));
		if (!tmp)
		{
			(del)(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	tmp->next = NULL;
	return (new);
}

// void del(void *content)
// {
// 	free(content);
// }

// void *my_fonct(void *c)
// {
// 	c = c +20;
// 	return (c);
// }

// void print_int_list(t_list *head)
// {
//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("%d -> ", *(int *)current->content);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     int a = 42, b = 21, c = 84;

//     t_list *new;
// 	t_list *node1 = ft_lstnew(&a);
//     t_list *node2 = ft_lstnew(&b);
//     t_list *node3 = ft_lstnew(&c);
//     node1->next = node2;
//     node2->next = node3;
// 	new = ft_lstmap(node1, my_fonct, del);
// 	print_int_list(new);
//     return 0;
// }