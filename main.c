/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/13 15:54:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			setup_turn(t_play *play, int *part)
{
	if (!(play->plateau = (t_plateau *)malloc(sizeof(t_plateau) * 1)))
		ft_exit("Could not allocate plateau");
	if (!(play->piece = (t_piece *)malloc(sizeof(t_piece) * 1)))
		ft_exit("Could not allocate piece");
	if (!(play->dir = (t_direction *)malloc(sizeof(t_direction) * 1)))
		ft_exit("Could not allocate direction");
	play->player = 0;
	play->plateau->x = 0;
	play->plateau->y = 0;
	play->piece->x = 0;
	play->piece->y = 0;
	play->dir->up = FALSE;
	play->dir->down = FALSE;
	play->dir->left = FALSE;
	play->dir->right = FALSE;
	play->x = 0;
	play->y = 0;
	part[0] = 0;
	part[1] = 0;
	part[2] = 0;
}

int				main(void)
{
	t_play		*play;
	int			part[3];

	if (!play)
		if (!(play = (t_play *)malloc(sizeof(t_play) * 1)))
			ft_exit("Could not allocate play");
	setup_turn(play, part);
	if (parse_turn(play, part) == -1)
	{
		free(play);
		ft_putendl("0 0");
	}
	return (0);
}
