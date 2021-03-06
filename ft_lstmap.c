/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:56:43 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/14 09:51:11 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (f && lst)
	{
		new = (t_list*)malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
