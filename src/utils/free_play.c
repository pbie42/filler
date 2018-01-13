/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/13 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define PIECE play->piece->piece
#define REAL play->piece->real
#define TERR play->piece->terr
#define TOP play->piece->terr->top
#define BOTTOM play->piece->terr->bottom
#define LEFT play->piece->terr->left
#define RIGHT play->piece->terr->right
#define HEIGHT (BOTTOM->y + 1) - TOP->y
#define WIDTH (RIGHT->x + 1) - LEFT->x

void					free_piece(t_play *play)
{
	int				y;

	y = play->piece->y + 1;
	while (--y >= 0)
		free(PIECE[y]);
	free(PIECE);
}

void					free_real_piece(t_play *play)
{
	int				y;

	y = HEIGHT + 1;
	while (--y >= 0)
		free(REAL[y]);
	free(play->piece->real);
}

void					free_board(t_play *play)
{
	int				y;

	y = play->plateau->y + 1;
	while (--y >= 0)
		free(BOARD[y]);
	free(play->plateau->board);
}

void					free_play(t_play *play)
{
	free_board(play);
	free_piece(play);
	free_real_piece(play);
	free(play->plateau);
	free(play->piece->terr->top);
	free(play->piece->terr->bottom);
	free(play->piece->terr->left);
	free(play->piece->terr->right);
	free(play->piece->terr);
	free(play->piece);
	free(play->territory->top);
	free(play->territory->bottom);
	free(play->territory->left);
	free(play->territory->right);
	free(play->territory);
	free(play->enemy->top);
	free(play->enemy->bottom);
	free(play->enemy->left);
	free(play->enemy->right);
	free(play->enemy);
	free(play->dir);
}
