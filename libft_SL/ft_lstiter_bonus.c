/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:22:35 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 11:29:49 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void my_f(t_list *lst)
// {
// 	printf("%d ", lst->content);
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
//     ft_lstiter(node1, my_f);
//     return 0;
// }