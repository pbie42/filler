/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/12 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				enemy_setup(t_play *play)
{
	play->enemy->top->x = 0;
	play->enemy->top->y = 0;
	play->enemy->bottom->x = 0;
	play->enemy->bottom->y = 0;
	play->enemy->left->x = 0;
	play->enemy->left->y = 0;
	play->enemy->right->x = 0;
	play->enemy->right->y = 0;
	if (play->symbol == 'o')
		play->e_symbol = 'x';
	else
		play->e_symbol = 'o';
}
