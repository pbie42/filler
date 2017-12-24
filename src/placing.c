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
#define DIR play->dir

void					find_direction(t_play *play)
{
	// ft_putendlnbr("ENEMY->top->x ", ENEMY->top->x);
	// ft_putendlnbr("ENEMY->bottom->x ", ENEMY->bottom->x);
	// ft_putendlnbr("ME->top->x ", ME->top->x);
	// ft_putendlnbr("ME->bottom->x ", ME->bottom->x);
	if (ENEMY->top->y > ME->bottom->y || ENEMY->bottom->y > ME->bottom->y)
	{
		DIR->down = TRUE;
		// ft_putendl("down is true");
	}
	if (ENEMY->bottom->y < ME->top->y || ENEMY->top->y < ME->top->y)
	{
		DIR->up = TRUE;
		// ft_putendl("up is true");
	}
	// ft_putendlnbr("ENEMY->right->x ", ENEMY->right->x);
	// ft_putendlnbr("ENEMY->left->x ", ENEMY->left->x);
	// ft_putendlnbr("ME->right->x ", ME->right->x);
	// ft_putendlnbr("ME->left->x ", ME->left->x);
	if (ENEMY->right->x < ME->left->x || ENEMY->left->x < ME->left->x)
	{
		DIR->left = TRUE;
		// ft_putendl("left is true");
	}
	if (ENEMY->left->x > ME->right->x || ENEMY->right->x > ME->right->x)
	{
		DIR->right = TRUE;
		// ft_putendl("right is true");
	}
}

void					place_piece(t_play *play)
{
	find_direction(play);
	if (DIR->down && DIR->right)
		ft_putendl("down right");
	else if (DIR->down && DIR->left)
		ft_putendl("down left");
	else if (DIR->up && DIR->right)
		ft_putendl("up right");
	else if (DIR->up && DIR->left)
		ft_putendl("up left");
	else if (DIR->up)
		ft_putendl("up");
	else if (DIR->down)
		ft_putendl("down");
	else if (DIR->left)
		ft_putendl("left");
	else if (DIR->right)
		ft_putendl("right");
}