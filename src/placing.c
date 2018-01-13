/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/13 19:45:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define PIECE play->piece->piece
#define REAL play->piece->real
#define TOP play->piece->terr->top
#define BOTTOM play->piece->terr->bottom
#define LEFT play->piece->terr->left
#define RIGHT play->piece->terr->right
#define ENEMY play->enemy
#define ME play->territory
#define DIR play->dir
#define WIDTH (RIGHT->x + 1) - LEFT->x
#define HEIGHT (BOTTOM->y + 1) - TOP->y
#define TOPDIFF (ME->top->y - ENEMY->top->y)
#define BOTTOMDIFF (ENEMY->bottom->y - ME->bottom->y)
#define RIGHTDIFF (ENEMY->right->x - ME->right->x)
#define LEFTDIFF (ME->left->x - ENEMY->left->x)

t_bool				can_place_bis(t_play *play, int x, int y, int count)
{
	if (count == 1)
	{
		play->x = x - LEFT->x;
		play->y = y - TOP->y;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool				can_place(t_play *play, int x, int y)
{
	int				px;
	int				py;
	int				count;

	py = -1;
	count = 0;
	while (REAL[++py])
	{
		px = -1;
		while (REAL[py][++px])
		{
			if (REAL[py][px] == '*' && (y + py) <= play->plateau->y
				&& (x + px) < play->plateau->x
				&& (BOARD[y + py][x + px] == play->symbol
				|| BOARD[y + py][x + px] == ft_toupper(play->symbol)))
				count++;
			if (REAL[py][px] == '*' && (y + py) <= play->plateau->y
				&& (x + px) < play->plateau->x
				&& (BOARD[y + py][x + px] == play->e_symbol
				|| BOARD[y + py][x + px] == ft_toupper(play->e_symbol)))
				return (FALSE);
		}
	}
	return (can_place_bis(play, x, y, count));
}

void				find_direction(t_play *play)
{
	if (ENEMY->top->y > ME->bottom->y || ENEMY->bottom->y > ME->bottom->y)
		DIR->down = TRUE;
	if (ENEMY->bottom->y < ME->top->y || ENEMY->top->y < ME->top->y)
		DIR->up = TRUE;
	if (ENEMY->right->x < ME->left->x || ENEMY->left->x < ME->left->x)
		DIR->left = TRUE;
	if (ENEMY->left->x > ME->right->x || ENEMY->right->x > ME->right->x)
		DIR->right = TRUE;
}

int					place_anywhere(t_play *play)
{
	int				x;
	int				y;

	y = play->plateau->y - HEIGHT;
	while (y >= 0)
	{
		x = -1;
		while (BOARD[y][++x + WIDTH - 1])
		{
			if (can_place(play, x, y))
			{
				if (x >= 0 && x <= play->plateau->x
					&& y >= 0 && y <= play->plateau->y)
				{
					ft_printf("%d %d\n", play->y, play->x);
					return (1);
				}
			}
		}
		y--;
	}
	free_play(play);
	return (-1);
}

int					place_piece(t_play *play)
{
	find_direction(play);
	if (DIR->up && TOPDIFF > BOTTOMDIFF)
		return (up_priority(play));
	else if (DIR->down && BOTTOMDIFF > TOPDIFF)
		return (down_priority(play));
	else if (DIR->right && RIGHTDIFF > LEFTDIFF)
		return (right_priority(play));
	else if (DIR->left && LEFTDIFF > RIGHTDIFF)
		return (left_priority(play));
	else
		return (up_priority(play));
	return (-1);
}
