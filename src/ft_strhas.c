/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/28 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_strhas(const char *s1, const char *s2)
{
	int			x;
	int			y;

	x = -1;
	// ft_putstr("s1 is ");
	// ft_putendl(s1);
	while (s1[++x])
	{
		y = 0;
		while (s1[x + y] && s2[y] && s1[x + y] == s2[y])
		{
			// ft_putstr("s1[x + y] is ");
			// ft_putchar(s1[x + y]);
			// ft_putchar('\n');
			// ft_putstr("s2[y] is ");
			// ft_putchar(s2[y]);
			// ft_putchar('\n');
			y++;
		}
		if (s2[y] == '\0')
			return (1);
	}
	return (0);
}