/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:23:33 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/04 13:38:19 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	void	*temp;
	t_list	*newlst;

	newlst = 0;
	while (lst)
	{
		temp = (*f)(lst->content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del(temp);
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
// void	del(void *content)
// {
// 	free(content);
// }

// void	f(void *content)
// {
// 	int		i;
// 	char	*j;

// 	i = 0;
// 	j = (char *) content;
// 	while (j[i])
// 	{
// 		j[i] = j[i] + 10;
// 		i++;
// 	}
// }

// int main (void)
// {
// 	t_list	*lst;
// 	t_list	*newlst;

// 	lst = ft_lstnew(ft_strdup("lorem"));
// 	lst->next = ft_lstnew(ft_strdup("abc"));
// 	lst->next->next = ft_lstnew (ft_strdup("ijk"));
// 	newlst = ft_lstmap(lst, (void*)f, del);

// 	while (newlst)
// 	{
// 		printf("%s\n", newlst->content);
// 		newlst = newlst->next;
// 	}
// }