/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define TOP play->territory->top
#define BOTTOM play->territory->bottom
#define LEFT play->territory->left
#define RIGHT play->territory->right

void					find_top(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while(BOARD[++y])
	{
		x = -1;
		while(BOARD[y][++x])
			if (BOARD[y][x] == play->symbol
				|| BOARD[y][x] == ft_toupper(play->symbol))
			{
				TOP->x = x;
				TOP->y = y;
				return ;
			}
	}
}

void					find_bottom(t_play *play)
{
	int				x;
	int				y;

	y = play->plateau->y;
	while(--y >= 0)
	{
		x = -1;
		while(BOARD[y][++x])
			if (BOARD[y][x] == play->symbol
				|| BOARD[y][x] == ft_toupper(play->symbol))
			{
				BOTTOM->x = x;
				BOTTOM->y = y;
				return ;
			}
	}
}

void					find_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while(++x <= play->plateau->x)
	{
		y = -1;
		while(BOARD[++y])
			if (BOARD[y][x] == play->symbol
				|| BOARD[y][x] == ft_toupper(play->symbol))
			{
				LEFT->x = x;
				LEFT->y = y;
				return ;
			}
	}
}

void					find_right(t_play *play)
{
	int				x;
	int				y;

	x = play->plateau->x;
	while(--x <= 0)
	{
		y = -1;
		while(BOARD[++y])
			if (BOARD[y][x] == play->symbol
				|| BOARD[y][x] == ft_toupper(play->symbol))
			{
				RIGHT->x = x;
				RIGHT->y = y;
				return ;
			}
	}
}

void					find_territory(t_play *play)
{
	if (!(play->territory = (t_territory *)malloc(sizeof(t_territory) * 1)))
		ft_exit("Could not allocate territory");
	if (!(play->territory->top = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate top");
	if (!(play->territory->bottom = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate bottom");
	if (!(play->territory->left = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate left");
	if (!(play->territory->right = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate right");
	ft_putendl("before territory");
	play->territory->top->x = 0;
	play->territory->top->y = 0;
	ft_putendl("after top");
	play->territory->bottom->x = 0;
	play->territory->bottom->y = 0;
	play->territory->left->x = 0;
	play->territory->left->y = 0;
	play->territory->right->x = 0;
	play->territory->right->y = 0;
	find_top(play);
	find_bottom(play);
	find_left(play);
	find_right(play);
	ft_putendl("found it all");
}