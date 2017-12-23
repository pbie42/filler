/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define ENEMY play->enemy
#define ME play->territory

void					find_direction(t_play *play)
{
	if (ENEMY->top->y < ME->bottom->y)
	if (ENEMY->bottom->y > ME->top->y)
	if (ENEMY->right->x < ME->left->x)
	if (ENEMY->left->x > ME->right->x)
}

void					place_piece(t_play *play)
{
	find_direction(play);
}