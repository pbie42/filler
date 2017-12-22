/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/09 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				setup_struct(t_play *play)
{
	if (!play->plateau)
		if (!(play->plateau = (t_plateau *)malloc(sizeof(t_plateau) * 1)))
			ft_exit("Could not allocate plateau");
	if (!play->piece)
		if (!(play->piece = (t_piece *)malloc(sizeof(t_piece) * 1)))
			ft_exit("Could not allocate piece");
	play->player = 0;
	play->plateau->x = 0;
	play->plateau->y = 0;
	play->piece->x = 0;
	play->piece->y = 0;
}

int				main(void)
{
	int			i;
	char			*str;
	char			**line;
	t_play		*play;

	if (!play)
		if (!(play = (play *)malloc(sizeof(play) * 1)))
			ft_exit("Could not allocate play");
	setup_struct(play);
	i = 0;
	while (ft_get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');

	}
	while(line[i])
	{
		ft_putendl("we are in here fuckkkk");
		ft_putendl(line[i]);
		i++;
	}
	
	return (0);
}
