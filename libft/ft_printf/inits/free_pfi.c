/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pfi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/12/12 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				free_pfi(t_pf_item *pfi)
{
	free(pfi->cspecs);
	free(pfi->flags);
	free(pfi->lenmods);
	free(pfi);
}