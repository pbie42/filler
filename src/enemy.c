/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define TOP play->enemy->top
#define BOTTOM play->enemy->bottom
#define LEFT play->enemy->left
#define RIGHT play->enemy->right

void					enemy_top(t_play *play)
{
	int				x;
	int				y;

	y = -1;
	while (BOARD[++y])
	{
		x = -1;
		while (BOARD[y][++x])
			if (BOARD[y][x] == play->e_symbol
				|| BOARD[y][x] == ft_toupper(play->e_symbol))
			{
				TOP->x = x;
				TOP->y = y;
				return ;
			}
	}
}

void					enemy_bottom(t_play *play)
{
	int				x;
	int				y;

	y = play->plateau->y;
	while (--y >= 0)
	{
		x = -1;
		while (BOARD[y][++x])
			if (BOARD[y][x] == play->e_symbol
				|| BOARD[y][x] == ft_toupper(play->e_symbol))
			{
				BOTTOM->x = x;
				BOTTOM->y = y;
				return ;
			}
	}
}

void					enemy_left(t_play *play)
{
	int				x;
	int				y;

	x = -1;
	while (++x <= play->plateau->x)
	{
		y = -1;
		while (BOARD[++y])
			if (BOARD[y][x] == play->e_symbol
				|| BOARD[y][x] == ft_toupper(play->e_symbol))
			{
				LEFT->x = x;
				LEFT->y = y;
				return ;
			}
	}
}

void					enemy_right(t_play *play)
{
	int				x;
	int				y;

	x = play->plateau->x;
	while (--x >= 0)
	{
		y = -1;
		while (BOARD[++y])
			if (BOARD[y][x] == play->e_symbol
				|| BOARD[y][x] == ft_toupper(play->e_symbol))
			{
				RIGHT->x = x;
				RIGHT->y = y;
				return ;
			}
	}
}

void					find_enemy(t_play *play)
{
	if (!(play->enemy = (t_territory *)malloc(sizeof(t_territory) * 1)))
		ft_exit("Could not allocate enemy");
	if (!(play->enemy->top = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate top");
	if (!(play->enemy->bottom = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate bottom");
	if (!(play->enemy->left = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate left");
	if (!(play->enemy->right = (t_coords *)malloc(sizeof(t_coords) * 1)))
		ft_exit("Could not allocate right");
	enemy_setup(play);
	enemy_top(play);
	enemy_bottom(play);
	enemy_left(play);
	enemy_right(play);
}
