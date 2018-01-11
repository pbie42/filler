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
#define DIR play->dir
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

	// ft_putendl("piece_right");
	x = play->plateau->x - WIDTH;
	while(--x >= 0)
	{
		if (DIR->down)
		{
			y = play->plateau->y - HEIGHT;
			while(--y >= 0 && BOARD[y])
			{
				if (can_place(play, x, y))
					return (TRUE);
			}
		}
		else
		{
			y = -1;
			while(BOARD[++y + HEIGHT])
				if (can_place(play, x, y))
					return (TRUE);
		}
	}
	return (FALSE);
}

t_bool					piece_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while((++x + WIDTH) <= play->plateau->x)
	{
		if (DIR->down)
		{
			y = play->plateau->y - HEIGHT;
			while(--y >= 0 && BOARD[y])
				if (can_place(play, x, y))
					return (TRUE);
		}
		else
		{
			y = -1;
			while(BOARD[++y + HEIGHT])
				if (can_place(play, x, y))
					return (TRUE);
		}
	}
	return (FALSE);
}

t_bool					piece_up(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while(BOARD[++y + HEIGHT])
	{
		if (DIR->right)
		{
			x = play->plateau->x - WIDTH + 1;
			while(BOARD[y][--x])
				if (can_place(play, x, y))
					return (TRUE);
		}
		else
		{
			x = -1;
			while(BOARD[y][++x + WIDTH])
				if (can_place(play, x, y))
					return (TRUE);
		}
	}
	return (FALSE);
}

t_bool					piece_down(t_play *play)
{
	int				x;
	int				y;

	// ft_putendl("piece_down");
	y = play->plateau->y - HEIGHT;
	while(--y >= 0)
	{
		if (DIR->right)
		{
			x = play->plateau->x - WIDTH + 1;
			while(BOARD[y][--x])
				if (can_place(play, x, y))
					return (TRUE);
		}
		else
		{
			x = -1;
			while(BOARD[y][++x + WIDTH])
				if (can_place(play, x, y))
					return (TRUE);
		}
	}
	return (FALSE);
}
