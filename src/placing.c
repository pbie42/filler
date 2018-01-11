/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
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

t_bool				can_place(t_play *play, int x, int y)
{
	int				px;
	int				py;
	int				count;

	py = -1;
	count = 0;
	// ft_putendlnbr("x ", x);
	// ft_putendlnbr("y ", y);
	// ft_putchar('\n');
	while(REAL[++py])
	{
		// ft_putendl("in can while y");
		px = -1;
		while(REAL[py][++px])
		{
			if (REAL[py][px] == '*' && (y + py) <= play->plateau->y
				&& (x + px) < play->plateau->x && (BOARD[y + py][x + px] == play->symbol
				|| BOARD[y + py][x + px] == ft_toupper(play->symbol)))
				count++;
			// if (BOARD[y + py][x + px] == play->e_symbol || BOARD[y + py][x + px] == ft_toupper(play->e_symbol))
			// 	ft_putendl("yooooooooooooooooo");
			if (REAL[py][px] == '*' && (y + py) <= play->plateau->y
				&& (x + px) < play->plateau->x && (BOARD[y + py][x + px] == play->e_symbol
				|| BOARD[y + py][x + px] == ft_toupper(play->e_symbol)))
			{
				// ft_putendl("e_symbol in way");
				return (FALSE);
			}
		}
	}
	if (count == 1)
	{
		// ft_putendl("count is fine");
		// ft_putendlnbr("x is ", x);
		// ft_putendlnbr("LEFT->x ", LEFT->x);
		// ft_putendlnbr("y is ", y);
		// ft_putendlnbr("TOP->y ", TOP->y);
		play->x = x - LEFT->x;
		play->y = y - TOP->y;
		return (TRUE);
	}
	else
	{
		// ft_putendlnbr("count is ", count);
		// ft_putendl("count is off");
		return (FALSE);
	}
}

void					find_direction(t_play *play)
{
	if (ENEMY->top->y > ME->bottom->y || ENEMY->bottom->y > ME->bottom->y)
	{
		DIR->down = TRUE;
	}
	if (ENEMY->bottom->y < ME->top->y || ENEMY->top->y < ME->top->y)
	{
		DIR->up = TRUE;
	}
	if (ENEMY->right->x < ME->left->x || ENEMY->left->x < ME->left->x)
	{
		DIR->left = TRUE;
	}
	if (ENEMY->left->x > ME->right->x || ENEMY->right->x > ME->right->x)
	{
		DIR->right = TRUE;
	}
}

void					find_og_direction(t_play *play)
{
	if (play->e_y > play->s_y)
	{
		play->r_dir->down = TRUE;
	}
	if (play->e_y < play->s_y)
	{
		play->r_dir->up = TRUE;
	}
	if (play->e_x < play->s_x)
	{
		play->r_dir->left = TRUE;
	}
	if (play->e_x > play->s_x)
	{
		play->r_dir->right = TRUE;
	}
}

void					place_anywhere(t_play * play)
{
	int				x;
	int				y;

	// ft_putendl("in place anywhere");
	y = play->plateau->y - HEIGHT;
	while (y >= 0)
	{
		x = -1;
		while (BOARD[y][++x + WIDTH - 1])
		{
			// // ft_putendl("y");
			// ft_putendlnbr("x ", x);
			// // ft_putendlnbr("y ", y);
			// ft_putendlnbr("y ", y);
			// ft_putchar('\n');
			// if (x == 5 && y == 13)
			// 	ft_putendl("WHERE WE SHOULD BE!!!!!");
			if (can_place(play, x, y))
			{
				// ft_putendl("can place it");
				if (x >= 0 && x <= play->plateau->x
					&& y >= 0 && y <= play->plateau->y)
				{
					ft_printf("%d %d\n", play->y, play->x);
					return ;
				}
			}
		}
		y--;
	}
	ft_putendl("0 0\n");
}

int					place_piece(t_play *play)
{
	int				x;

	x = 0;
	find_direction(play);
	find_og_direction(play);
	// ft_putendlnbr("DIR->right ", DIR->right);
	// ft_putendlnbr("DIR->left ", DIR->left);
	// ft_putendlnbr("DIR->down ", DIR->down);
	// ft_putendlnbr("DIR->up ", DIR->up);
	if (DIR->down && DIR->right)
	{
		// ft_putendl("down right");
		if ((x = piece_down_right(play)) != -1)
			return (x);
	}
	else if (DIR->down && DIR->left)
	{
		// ft_putendl("down left");
		if ((x = piece_down_left(play)) != -1)
		return (x);
	}
	else if (DIR->up && DIR->right)
	{
		// ft_putendl("up right");
		if ((x = piece_up_right(play)) != -1)
			return (x);
	}
	else if (DIR->up && DIR->left)
	{
		// ft_putendl("up left");
		return piece_up_left(play);
	}
	else if (DIR->up)
	{
		// ft_putendl("up");
		if (piece_up(play))
			return ft_printf("%d %d\n", play->y, play->x);
	}
	else if (DIR->down)
	{
		// ft_putendl("down");
		if (piece_down(play))
			return ft_printf("%d %d\n", play->y, play->x);
	}
	else if (DIR->left)
	{
		// ft_putendl("left");
		if (piece_left(play))
			return ft_printf("%d %d\n", play->y, play->x);
	}
	else if (DIR->right)
	{
		// ft_putendl("right");
		if (piece_right(play))
			return ft_printf("%d %d\n", play->y, play->x);
	}
	// ft_putendl("we here");
	place_anywhere(play);
	return -1;
}
