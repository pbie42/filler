/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_real.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/13 15:19:09 by pbie             ###   ########.fr       */
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
