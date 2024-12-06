/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:38 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 11:29:01 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

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
//     int a = 42, b = 21, c = 84
//     t_list *node1 = ft_lstnew(&a);
//     t_list *node2 = ft_lstnew(&b);
//     t_list *node3 = ft_lstnew(&c);
//     node1->next = node2;
//     node2->next = node3;
//     print_int_list(node1);
//     return 0;
// }