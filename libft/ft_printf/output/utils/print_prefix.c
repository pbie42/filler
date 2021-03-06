/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/30 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_prefix(t_pf_item *pfi)
{
	if (pfi->cspecs->x)
		ft_putstr("0x");
	else
		ft_putstr("0X");
}
