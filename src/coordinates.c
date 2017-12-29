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

#define ENEMY_T play->enemy->bottom
#define ENEMY_B play->enemy->bottom
#define ENEMY_L play->enemy->left
#define ENEMY_R play->enemy->right

void				dr_cmp(t_play *play, int x, int y)
{
	int			pc;
	int			xy;
	int			bottom;
	int			left;

	pc = (play->x * play->x) + (play->y * play->y);
	xy = (x * x) + (y * y);
	bottom = (ENEMY_B->x * ENEMY_B->x) + (ENEMY_B->y * ENEMY_B->y);
	left = (ENEMY_L->x * ENEMY_L->x) + (ENEMY_L->y * ENEMY_L->y);
	if ((bottom - pc) < (bottom - xy))
		if ((bottom - pc) < (left - pc))
			if ((bottom - pc) < (left - xy))
				ft_printf("%d %d\n", play->x, play->y);
	if ((bottom - xy) < (left - pc))
		if ((bottom - xy) < (left - xy))
			ft_printf("%d %d\n", x, y);
	if ((left - pc) < (left - xy))
		ft_printf("%d %d\n", play->x, play->y);
	else
		ft_printf("%d %d\n", x, y);

}
void				dl_cmp(t_play *play, int x, int y)
{
	int			pc;
	int			xy;
	int			bottom;
	int			right;

	pc = (play->x * play->x) + (play->y * play->y);
	xy = (x * x) + (y * y);
	bottom = (ENEMY_B->x * ENEMY_B->x) + (ENEMY_B->y * ENEMY_B->y);
	right = (ENEMY_R->x * ENEMY_R->x) + (ENEMY_R->y * ENEMY_R->y);
	if ((bottom - pc) < (bottom - xy))
		if ((bottom - pc) < (right - pc))
			if ((bottom - pc) < (right - xy))
				ft_printf("%d %d\n", play->x + 1, play->y + 1);
	if ((bottom - xy) < (right - pc))
		if ((bottom - xy) < (right - xy))
			ft_printf("%d %d\n", x + 1, y + 1);
	if ((right - pc) < (right - xy))
		ft_printf("%d %d\n", play->x + 1, play->y + 1);
	else
		ft_printf("%d %d\n", x + 1, y + 1);
}
void				ur_cmp(t_play *play, int x, int y)
{
	int			pc;
	int			xy;
	int			top;
	int			left;

	pc = (play->x * play->x) + (play->y * play->y);
	xy = (x * x) + (y * y);
	top = (ENEMY_T->x * ENEMY_T->x) + (ENEMY_T->y * ENEMY_T->y);
	left = (ENEMY_L->x * ENEMY_L->x) + (ENEMY_L->y * ENEMY_L->y);
	if ((top - pc) < (top - xy))
		if ((top - pc) < (left - pc))
			if ((top - pc) < (left - xy))
				ft_printf("%d %d\n", play->x + 1, play->y + 1);
	if ((top - xy) < (left - pc))
		if ((top - xy) < (left - xy))
			ft_printf("%d %d\n", x + 1, y + 1);
	if ((left - pc) < (left - xy))
		ft_printf("%d %d\n", play->x + 1, play->y + 1);
	else
		ft_printf("%d %d\n", x + 1, y + 1);
}
void				ul_cmp(t_play *play, int x, int y)
{
	int			pc;
	int			xy;
	int			top;
	int			right;

	pc = (play->x * play->x) + (play->y * play->y);
	xy = (x * x) + (y * y);
	top = (ENEMY_T->x * ENEMY_T->x) + (ENEMY_T->y * ENEMY_T->y);
	right = (ENEMY_R->x * ENEMY_R->x) + (ENEMY_R->y * ENEMY_R->y);
	if ((top - pc) < (top - xy))
		if ((top - pc) < (right - pc))
			if ((top - pc) < (right - xy))
				ft_printf("%d %d\n", play->x + 1, play->y + 1);
	if ((top - xy) < (right - pc))
		if ((top - xy) < (right - xy))
			ft_printf("%d %d\n", x + 1, y + 1);
	if ((right - pc) < (right - xy))
		ft_printf("%d %d\n", play->x + 1, play->y + 1);
	else
		ft_printf("%d %d\n", x + 1, y + 1);
}

void				compare_coords(t_play *play, int x, int y, char *str)
{
	// ft_putendl("in compare coords");
	// ft_putendlnbr("play->x ", play->x);
	// ft_putendlnbr("play->y ", play->y);
	// ft_putendlnbr("x ", x);
	// ft_putendlnbr("y ", y);

	if (play->x == x && play->y == y)
		ft_printf("%d %d\n", x, y);
	else if (ft_strcmp(str, "dr") == 0)
		dr_cmp(play, x, y);
	else if (ft_strcmp(str, "dl") == 0)
		dl_cmp(play, x, y);
	else if (ft_strcmp(str, "ul") == 0)
		ul_cmp(play, x, y);
	else if (ft_strcmp(str, "ur") == 0)
		ur_cmp(play, x, y);
}