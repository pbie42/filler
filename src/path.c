/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/12 15:19:09 by pbie             ###   ########.fr       */
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
#define TOPDIFF (ME->top->y - ENEMY->top->y)
#define BOTTOMDIFF (ENEMY->bottom->y - ME->bottom->y)
#define RIGHTDIFF (ENEMY->right->x - ME->right->x)
#define LEFTDIFF (ME->left->x - ENEMY->left->x)

int					down_priority(t_play *play)
{
	int				x;

	x = 0;
	if (DIR->down && DIR->right)
		if ((x = piece_down_right(play)) != -1)
			return (x);
	if (DIR->down && DIR->left)
		if ((x = piece_down_left(play)) != -1)
			return (x);
	if (DIR->up && DIR->right)
		if ((x = piece_up_right(play)) != -1)
			return (x);
	if (DIR->up && DIR->left)
		if ((x = piece_up_left(play)) != -1)
			return (x);
	if (DIR->up)
		if (piece_up(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->down)
		if (piece_down(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->left)
		if (piece_left(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->right)
		if (piece_right(play))
			return ft_printf("%d %d\n", play->y, play->x);
	place_anywhere(play);
	return (-1);
}

int					up_priority(t_play *play)
{
	int				x;

	x = 0;
	if (DIR->up && DIR->right)
		if ((x = piece_up_right(play)) != -1)
			return (x);
	if (DIR->up && DIR->left)
		if ((x = piece_up_left(play)) != -1)
			return (x);
	if (DIR->down && DIR->right)
		if ((x = piece_down_right(play)) != -1)
			return (x);
	if (DIR->down && DIR->left)
		if ((x = piece_down_left(play)) != -1)
			return (x);
	if (DIR->up)
		if (piece_up(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->down)
		if (piece_down(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->left)
		if (piece_left(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->right)
		if (piece_right(play))
			return ft_printf("%d %d\n", play->y, play->x);
	place_anywhere(play);
	return (-1);
}

int					left_priority(t_play *play)
{
	int				x;

	x = 0;
	if (DIR->up && DIR->left)
		if ((x = piece_up_left(play)) != -1)
			return (x);
	if (DIR->down && DIR->left)
		if ((x = piece_down_left(play)) != -1)
			return (x);
	if (DIR->up && DIR->right)
		if ((x = piece_up_right(play)) != -1)
			return (x);
	if (DIR->down && DIR->right)
		if ((x = piece_down_right(play)) != -1)
			return (x);
	if (DIR->up)
		if (piece_up(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->down)
		if (piece_down(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->left)
		if (piece_left(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->right)
		if (piece_right(play))
			return ft_printf("%d %d\n", play->y, play->x);
	place_anywhere(play);
	return (-1);
}

int					right_priority(t_play *play)
{
	int				x;

	x = 0;
	if (DIR->up && DIR->right)
		if ((x = piece_up_right(play)) != -1)
			return (x);
	if (DIR->down && DIR->right)
		if ((x = piece_down_right(play)) != -1)
			return (x);
	if (DIR->up && DIR->left)
		if ((x = piece_up_left(play)) != -1)
			return (x);
	if (DIR->down && DIR->left)
		if ((x = piece_down_left(play)) != -1)
			return (x);
	if (DIR->up)
		if (piece_up(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->down)
		if (piece_down(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->left)
		if (piece_left(play))
			return ft_printf("%d %d\n", play->y, play->x);
	if (DIR->right)
		if (piece_right(play))
			return ft_printf("%d %d\n", play->y, play->x);
	place_anywhere(play);
	return (-1);
}
