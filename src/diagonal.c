/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				piece_down_right(t_play *play)
{
	int			x;
	int			y;
	t_bool		down;
	t_bool		right;

	down = FALSE;
	right = FALSE;
	if (piece_down(play))
	{
		down = TRUE;
		x = play->x;
		y = play->y;
	}
	if (piece_right(play))
		right = TRUE;
	if (down)
	{
		if (right)
			return compare_coords(play, x, y, "dr");
		else
			return ft_printf("%d %d\n", y, x);
	}
	else if (right)
		return ft_printf("%d %d\n", play->y, play->x);
	return -1;
}

int				piece_down_left(t_play *play)
{
	int			x;
	int			y;
	t_bool		down;
	t_bool		left;

	down = FALSE;
	left = FALSE;
	if (piece_down(play))
	{
		down = TRUE;
		x = play->x;
		y = play->y;
	}
	if (piece_left(play))
		left = TRUE;
	if (down)
	{
		if (left)
			return compare_coords(play, x, y, "dl");
		else
			return ft_printf("%d %d\n", y, x);
	}
	else if (left)
		return ft_printf("%d %d\n", play->y, play->x);
	return -1;
}

int				piece_up_right(t_play *play)
{
	int			x;
	int			y;
	t_bool		up;
	t_bool		right;

	up = FALSE;
	right = FALSE;
	if (piece_up(play))
	{
		up = TRUE;
		x = play->x;
		y = play->y;
	}
	if (piece_right(play))
		right = TRUE;
	if (up)
	{
		if (right)
			return compare_coords(play, x, y, "ur");
		else
			return ft_printf("%d %d\n", y, x);
	}
	else if (right)
		return ft_printf("%d %d\n", play->y, play->x);
	return -1;
}

int				piece_up_left(t_play *play)
{
	int			x;
	int			y;
	t_bool		up;
	t_bool		left;

	up = FALSE;
	left = FALSE;
	// ft_putendl("before piece_down");
	if (piece_up(play))
	{
		// ft_putendl("in piece_down IF");
		up = TRUE;
		x = play->x;
		y = play->y;
	}
	// ft_putendl("after piece_down");
	if (piece_left(play))
		left = TRUE;
	if (up)
	{
		if (left)
			return compare_coords(play, x, y, "ul");
		else
			return ft_printf("%d %d\n", y, x);
	}
	else if (left)
		return ft_printf("%d %d\n", play->y, play->x);
	return -1;
}
