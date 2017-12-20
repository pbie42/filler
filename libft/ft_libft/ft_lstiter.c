/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:12:09 by pbie              #+#    #+#             */
/*   Updated: 2015/12/01 19:15:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f != NULL)
	{
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
