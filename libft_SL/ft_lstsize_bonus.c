/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:33:33 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 11:27:09 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list *new;

// 	new = malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
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
//     t_list *node1 = ft_lstnew(&a);
//     t_list *node2 = ft_lstnew(&b);
//     t_list *node3 = ft_lstnew(&c);
//     node1->next = node2;
//     node2->next = node3;
// 	printf("%d", ft_lstsize(node1));
//     return 0;
// }