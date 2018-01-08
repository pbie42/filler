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
	// ft_putendlnbr("WIDTH ", WIDTH);
	// ft_putendlnbr("HEIGHT ", HEIGHT);
	while(--x >= 0)
	{
		y = -1;
		// ft_putendl("x");
		while(BOARD[++y + HEIGHT])
		{
			// ft_putendl("y");
			// ft_putendlnbr("x ", x);
			// ft_putendlnbr("y ", y);
			// ft_putendlnbr("y + HEIGHT ", y + HEIGHT);
			// ft_putchar('\n');
			if (can_place(play, x, y))
			{
				// ft_putendl("can place on right!");
				return (TRUE);
			}
		}
	}
	// ft_putendl("can NOT place on right!");
	return (FALSE);
}

t_bool					piece_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while((++x + WIDTH) <= play->plateau->x)
	{
		y = -1;
		while(BOARD[++y + HEIGHT])
		{
			if (can_place(play, x, y))
			{
				// ft_putendl("can place on left!");
				return (TRUE);
			}
		}
	}
	// ft_putendl("can NOT place on left!");
	return (FALSE);
}

t_bool					piece_up(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while(BOARD[++y + HEIGHT])
	{
		x = -1;
		while(BOARD[y][++x + WIDTH])
			if (can_place(play, x, y))
			{
				// ft_putendl("can place on top!");
				return (TRUE);
			}
	}
	// ft_putendl("can NOT place on top!");
	return (FALSE);
}

t_bool					piece_down(t_play *play)
{
	int				x;
	int				y;

	y = play->plateau->y - HEIGHT;
	// ft_putendlnbr("play->plateau->y", play->plateau->y);
	while(--y >= 0)
	{
		// ft_putendl("in while");
		x = -1;
		while(BOARD[y][++x + WIDTH])
		{
			// ft_putendl("in x while");
			if (can_place(play, x, y))
			{
				// ft_putendl("can place on bottom!");
				return (TRUE);
			}
		}
	}
	// ft_putendl("can NOT place on bottom!");
	return (FALSE);
}
