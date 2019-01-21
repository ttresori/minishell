/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 16:58:54 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*bgn;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	bgn = tmp;
	next = lst->next;
	*tmp = *(f(lst));
	lst = next;
	while (lst != NULL)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp = tmp->next;
		if (!tmp)
			return (NULL);
		next = lst->next;
		*tmp = *(f(lst));
		lst = next;
	}
	return (bgn);
}
