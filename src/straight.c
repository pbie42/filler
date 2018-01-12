/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define TOP play->piece->terr->top
#define BOTTOM play->piece->terr->bottom
#define LEFT play->piece->terr->left
#define RIGHT play->piece->terr->right
#define WIDTH (RIGHT->x + 1) - LEFT->x
#define HEIGHT (BOTTOM->y + 1) - TOP->y

t_bool					piece_right(t_play *play)
{
	int				x;
	int				y;

	x = play->plateau->x - WIDTH;
	while (--x >= 0)
	{
		y = -1;
		while (BOARD[++y + HEIGHT])
			if (can_place(play, x, y))
				return (TRUE);
	}
	return (FALSE);
}

t_bool					piece_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while ((++x + WIDTH) <= play->plateau->x)
	{
		y = -1;
		while (BOARD[++y + HEIGHT])
			if (can_place(play, x, y))
				return (TRUE);
	}
	return (FALSE);
}

t_bool					piece_up(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while (BOARD[++y + HEIGHT])
	{
		x = -1;
		while (BOARD[y][++x + WIDTH])
			if (can_place(play, x, y))
				return (TRUE);
	}
	return (FALSE);
}

t_bool					piece_down(t_play *play)
{
	int				x;
	int				y;

	y = play->plateau->y - HEIGHT;
	while (--y >= 0)
	{
		x = -1;
		while (BOARD[y][++x + WIDTH])
			if (can_place(play, x, y))
				return (TRUE);
	}
	return (FALSE);
}
