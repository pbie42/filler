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
#define TERR play->piece->terr
#define TOP play->piece->terr->top
#define BOTTOM play->piece->terr->bottom
#define LEFT play->piece->terr->left
#define RIGHT play->piece->terr->right

void					find_piece_top(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	// ft_putendl("in top");
	while (PIECE[++y])
	{
		// ft_putendl("in top y");
		x = -1;
		while(PIECE[y][++x])
		{
			// ft_putendl("in top x");
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
	while(--y >= 0)
	{
		x = -1;
		while(PIECE[y][++x])
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
	while(++x <= play->piece->x)
	{
		y = -1;
		while(PIECE[++y])
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
	while(--x >= 0)
	{
		y = -1;
		while(PIECE[++y])
			if (PIECE[y][x] == '*')
			{
				RIGHT->x = x;
				RIGHT->y = y;
				return ;
			}
	}
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
	// ft_putendl("after allocation of find piece");
	TOP->y = 0;
	TOP->x = 0;
	BOTTOM->x = 0;
	BOTTOM->y = 0;
	LEFT->x = 0;
	LEFT->y = 0;
	RIGHT->x = 0;
	RIGHT->y = 0;
	// ft_putendl("before find piece!");
	find_piece_top(play);
	// ft_putendl("after top");
	find_piece_bottom(play);
	// ft_putendl("after bottom");
	find_piece_left(play);
	// ft_putendl("after left");
	find_piece_right(play);
	// ft_putendl("after right");
	// ft_putendl("found all of PIECE!!");
	// ft_putendlnbr("play->piece->terr->bottom->x", BOTTOM->x);
	// ft_putendlnbr("play->piece->terr->bottom->y", BOTTOM->y);
	// ft_putendlnbr("play->piece->terr->top->x", TOP->x);
	// ft_putendlnbr("play->piece->terr->top->y", TOP->y);
	// ft_putendlnbr("play->piece->terr->left->x", LEFT->x);
	// ft_putendlnbr("play->piece->terr->left->y", LEFT->y);
	// ft_putendlnbr("play->piece->terr->right->x", RIGHT->x);
	// ft_putendlnbr("play->piece->terr->right->y", RIGHT->y);
}