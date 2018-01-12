/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/07 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define PIECE play->piece->piece
#define REAL play->piece->real
#define TERR play->piece->terr
#define TOP play->piece->terr->top
#define BOTTOM play->piece->terr->bottom
#define LEFT play->piece->terr->left
#define RIGHT play->piece->terr->right
#define HEIGHT (BOTTOM->y + 1) - TOP->y
#define WIDTH (RIGHT->x + 1) - LEFT->x

void					find_piece_top(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while (PIECE[++y])
	{
		x = -1;
		while (PIECE[y][++x])
		{
			if (PIECE[y][x] == '*')
			{
				TOP->x = x;
				TOP->y = y;
				return ;
			}
		}
	}
}

void					find_piece_bottom(t_play *play)
{
	int				x;
	int				y;

	y = play->piece->y;
	while (--y >= 0)
	{
		x = -1;
		while (PIECE[y][++x])
			if (PIECE[y][x] == '*')
			{
				BOTTOM->x = x;
				BOTTOM->y = y;
				return ;
			}
	}
}

void					find_piece_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while (++x <= play->piece->x)
	{
		y = -1;
		while (PIECE[++y])
			if (PIECE[y][x] == '*')
			{
				LEFT->x = x;
				LEFT->y = y;
				return ;
			}
	}
}

void					find_piece_right(t_play *play)
{
	int				x;
	int				y;

	x = play->piece->x;
	while (--x >= 0)
	{
		y = -1;
		while (PIECE[++y])
			if (PIECE[y][x] == '*')
			{
				RIGHT->x = x;
				RIGHT->y = y;
				return ;
			}
	}
}

void					malloc_real(t_play *play)
{
	int					x;
	int					y;
	int					left;
	int					top;

	y = 0;
	top = TOP->y;
	while (top <= BOTTOM->y)
	{
		x = 0;
		left = LEFT->x;
		if (!(REAL[y] = (char *)malloc(sizeof(char) * WIDTH + 1)))
			ft_exit("Could not allocate line of real piece");
		while (left <= RIGHT->x)
		{
			REAL[y][x] = PIECE[top][left];
			left++;
			x++;
		}
		top++;
		y++;
	}
	REAL[y] = NULL;
}

void					find_piece(t_play *play)
{
	if (!(TERR = (t_territory *)malloc(sizeof(t_territory) * 1)))
		ft_exit("Could not allocate piece territory");
	if (!(TOP = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate piece top");
	if (!(BOTTOM = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate piece bottom");
	if (!(LEFT = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate piece left");
	if (!(RIGHT = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate piece right");
	TOP->y = 0;
	TOP->x = 0;
	BOTTOM->x = 0;
	BOTTOM->y = 0;
	LEFT->x = 0;
	LEFT->y = 0;
	RIGHT->x = 0;
	RIGHT->y = 0;
	find_piece_top(play);
	find_piece_bottom(play);
	find_piece_left(play);
	find_piece_right(play);
	if (!(REAL = (char **)malloc(sizeof(char *) * HEIGHT + 1)))
		ft_exit("Could not allocate real piece");
	malloc_real(play);
}
