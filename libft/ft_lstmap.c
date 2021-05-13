/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:18:11 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 18:33:51 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	const t_list	*tmp;
	t_list			*list;
	t_list			*new;
	void			*f_success;

	tmp = lst;
	while (tmp)
	{
		if ((f_success = f(tmp->content)))
		{
			if (!(new = ft_lstnew(f_success)))
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			else
				ft_lstadd_back(&list, new);
		}
		tmp = tmp->next;
	}
	return (list);
}
