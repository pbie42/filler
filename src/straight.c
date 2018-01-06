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

t_bool					piece_right(t_play *play)
{
	int				x;
	int				y;

	x = play->plateau->x;
	while((--x - play->piece->x) >= 0)
	{
		y = -1;
		// ft_putendl("x");
		while(BOARD[++y + play->piece->y])
		{
			// ft_putendl("y");
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
	while((++x + play->piece->x) <= play->plateau->x)
	{
		y = -1;
		while(BOARD[++y + play->piece->y])
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
	while(BOARD[++y + play->piece->y])
	{
		x = -1;
		while(BOARD[y][++x + play->piece->x])
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

	// ft_putendl("in piece_down");
	y = play->plateau->y;
	// ft_putendlnbr("play->plateau->y", play->plateau->y);
	while((--y - play->piece->y) >= 0)
	{
		// ft_putendl("in while");
		x = -1;
		while(BOARD[y][++x + play->piece->x])
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
