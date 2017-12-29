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
#define ENEMY play->enemy
#define ME play->territory
#define DIR play->dir

t_bool				can_place(t_play *play, int x, int y)
{
	int				px;
	int				py;
	int				count;

	py = -1;
	count = 0;
	// ft_putendl("in can place");
	while(PIECE[++py])
	{
		// ft_putendl("in can while y");
		px = -1;
		while(PIECE[py][++px])
		{
			// ft_putendl("in can while x");
			// ft_putendlnbr("py", py);
			// ft_putendlnbr("px", px);
			// ft_putendlnbr("y", y);
			// ft_putendlnbr("x", x);
			// ft_putstr("piece is ");
			// ft_putchar(PIECE[py][px]);
			// ft_putstr("board is ");
			// ft_putchar(BOARD[y + py][x + px]);
			if (PIECE[py][px] == '*' && (y + py) < play->plateau->y
				&& (x + px) < play->plateau->x && (BOARD[y + py][x + px] == play->symbol
				|| BOARD[y + py][x + px] == ft_toupper(play->symbol)))
				count++;
			// if (BOARD[y + py][x + px] == play->e_symbol || BOARD[y + py][x + px] == ft_toupper(play->e_symbol))
			// 	ft_putendl("yooooooooooooooooo");
			if (PIECE[py][px] == '*' && (y + py) < play->plateau->y
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
		play->x = x;
		play->y = y;
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
	// ft_putendlnbr("ENEMY->top->x ", ENEMY->top->x);
	// ft_putendlnbr("ENEMY->bottom->x ", ENEMY->bottom->x);
	// ft_putendlnbr("ME->top->x ", ME->top->x);
	// ft_putendlnbr("ME->bottom->x ", ME->bottom->x);
	if (ENEMY->top->y > ME->bottom->y || ENEMY->bottom->y > ME->bottom->y)
	{
		DIR->down = TRUE;
		// ft_putendl("down is true");
	}
	if (ENEMY->bottom->y < ME->top->y || ENEMY->top->y < ME->top->y)
	{
		DIR->up = TRUE;
		// ft_putendl("up is true");
	}
	// ft_putendlnbr("ENEMY->right->x ", ENEMY->right->x);
	// ft_putendlnbr("ENEMY->left->x ", ENEMY->left->x);
	// ft_putendlnbr("ME->right->x ", ME->right->x);
	// ft_putendlnbr("ME->left->x ", ME->left->x);
	if (ENEMY->right->x < ME->left->x || ENEMY->left->x < ME->left->x)
	{
		DIR->left = TRUE;
		// ft_putendl("left is true");
	}
	if (ENEMY->left->x > ME->right->x || ENEMY->right->x > ME->right->x)
	{
		DIR->right = TRUE;
		// ft_putendl("right is true");
	}
}

void					place_piece(t_play *play)
{
	find_direction(play);
	if (DIR->down && DIR->right)
	{
		// ft_putendl("down right");
		// piece_down(play);
		// piece_right(play);
		piece_down_right(play);
	}
	else if (DIR->down && DIR->left)
	{
		// ft_putendl("down left");
		// piece_down(play);
		// piece_left(play);
		piece_down_left(play);
	}
	else if (DIR->up && DIR->right)
	{
		// ft_putendl("up right");
		// piece_up(play);
		// piece_right(play);
		piece_up_right(play);
	}
	else if (DIR->up && DIR->left)
	{
		// ft_putendl("up left");
		// piece_up(play);
		// piece_left(play);
		piece_up_left(play);
	}
	else if (DIR->up)
	{
		// ft_putendl("up");
		if (piece_up(play))
			ft_printf("%d %d\n", play->x + 1, play->y + 1);
	}
	else if (DIR->down)
	{
		// ft_putendl("down");
		if (piece_down(play))
			ft_printf("%d %d\n", play->x + 1, play->y + 1);
	}
	else if (DIR->left)
	{
		// ft_putendl("left");
		if (piece_left(play))
			ft_printf("%d %d\n", play->x + 1, play->y + 1);
	}
	else if (DIR->right)
	{
		// ft_putendl("right");
		if (piece_right(play))
			ft_printf("%d %d\n", play->x + 1, play->y + 1);
	}
}