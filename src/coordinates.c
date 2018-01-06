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

int				dr_cmp(t_play *play, int x, int y)
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
				return ft_printf("%d %d\n", play->y, play->x);
	if ((bottom - xy) < (left - pc))
		if ((bottom - xy) < (left - xy))
			return ft_printf("%d %d\n", y, x);
	if ((left - pc) < (left - xy))
		return ft_printf("%d %d\n", play->y, play->x);
	else
		return ft_printf("%d %d\n", y, x);

}
int				dl_cmp(t_play *play, int x, int y)
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
				return ft_printf("%d %d\n", play->y, play->x);
	if ((bottom - xy) < (right - pc))
		if ((bottom - xy) < (right - xy))
			return ft_printf("%d %d\n", y, x);
	if ((right - pc) < (right - xy))
		return ft_printf("%d %d\n", play->y, play->x);
	else
		return ft_printf("%d %d\n", y, x);
}
int				ur_cmp(t_play *play, int x, int y)
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
				return ft_printf("%d %d\n", play->y, play->x);
	if ((top - xy) < (left - pc))
		if ((top - xy) < (left - xy))
			return ft_printf("%d %d\n", y, x);
	if ((left - pc) < (left - xy))
		return ft_printf("%d %d\n", play->y, play->x);
	else
		return ft_printf("%d %d\n", y, x);
}
int				ul_cmp(t_play *play, int x, int y)
{
	int			pc;
	int			xy;
	int			top;
	int			right;

	// ft_putendl("in ul_cmp");
	pc = (play->x * play->x) + (play->y * play->y);
	xy = (x * x) + (y * y);
	top = (ENEMY_T->x * ENEMY_T->x) + (ENEMY_T->y * ENEMY_T->y);
	right = (ENEMY_R->x * ENEMY_R->x) + (ENEMY_R->y * ENEMY_R->y);
	if ((top - pc) < (top - xy))
		if ((top - pc) < (right - pc))
			if ((top - pc) < (right - xy))
				return ft_printf("%d %d\n", play->y, play->x);
	if ((top - xy) < (right - pc))
		if ((top - xy) < (right - xy))
			return ft_printf("%d %d\n", y, x);
	if ((right - pc) < (right - xy))
		return ft_printf("%d %d\n", play->y, play->x);
	else
		return ft_printf("%d %d\n", y, x);
}

int				compare_coords(t_play *play, int x, int y, char *str)
{
	// ft_putendl("in compare coords");
	// ft_putendlnbr("play->x ", play->x);
	// ft_putendlnbr("play->y ", play->y);
	// ft_putendlnbr("x ", x);
	// ft_putendlnbr("y ", y);

	if (play->x == x && play->y == y)
		return ft_printf("%d %d\n", y, x);
	else if (ft_strcmp(str, "dr") == 0)
		return dr_cmp(play, x, y);
	else if (ft_strcmp(str, "dl") == 0)
		return dl_cmp(play, x, y);
	else if (ft_strcmp(str, "ul") == 0)
		return ul_cmp(play, x, y);
	else if (ft_strcmp(str, "ur") == 0)
		return ur_cmp(play, x, y);
	return -1;
}
