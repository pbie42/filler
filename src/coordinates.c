/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/23 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



void				compare_coords(t_play *play, int x, int y)
{
	ft_putendl("in compare coords");
	ft_putendlnbr("play->x ", play->x);
	ft_putendlnbr("play->y ", play->y);
	ft_putendlnbr("x ", x);
	ft_putendlnbr("y ", y);

	if (play->x == x && play->y == y)
		ft_printf("%d %d\n", x, y);
	else
		ft_putendl("nope");
	// if (ft_strcmp(str, "dr") == 0)
	// {
		
	// }
	// if (ft_strcmp(str, "dl") == 0)
	// {

	// }
	// if (ft_strcmp(str, "ul") == 0)
	// {

	// }
	// if (ft_strcmp(str, "ur") == 0)
	// {

	// }
}