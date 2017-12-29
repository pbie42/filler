/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/22 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define BOARD play->plateau->board
#define PIECE play->piece->piece

void				put_board(t_play *play)
{
	int			y;

	// ft_putendl(BOARD[0]);
	y = -1;
	while(BOARD[++y])
	{
		ft_putendl(BOARD[y]);
	}
}

void				parse_piece(t_play *play, int *part, char **line)
{
	// ft_putendl("parse_piece");
	if (part[2] == 0)
	{
		play->piece->y = ft_atoi(line[1]);
		play->piece->x = ft_atoi(line[2]);
		if (!(PIECE = (char **)malloc(sizeof(char *) * play->piece->y + 1)))
			ft_exit("Could not allocate PIECE");
		PIECE[play->piece->y] = NULL;
	}
	else if (part[2])
		PIECE[part[2] - 1] = ft_strdup(line[0]);
	part[2]++;
	if (part[2] == play->piece->y + 1)
	{
		find_territory(play);
		find_enemy(play);
		// ft_putstr("e_symbol is ");
		// ft_putchar(play->e_symbol);
		// ft_putchar('\n');
		place_piece(play);
	}
}

void				parse_plateau(t_play *play, int *part, char **line)
{
	// ft_putendl("parse_plateau");
	if (part[1] == 0)
	{
		play->plateau->y = ft_atoi(line[1]);
		play->plateau->x = ft_atoi(line[2]);
		if (!(BOARD = (char **)malloc(sizeof(char *) * play->plateau->y + 1)))
			ft_exit("Could not allocate BOARD");
		BOARD[play->plateau->y] = NULL;
	}
	if (part[1] > 1)
		BOARD[part[1] - 2] = ft_strdup(line[1]);
	part[1]++;
}

t_bool				parse_player(t_play *play, int *part, char **line)
{
	// ft_putendl("parse_player");
	if (!ft_strhas(line[4], "pbie"))
	{
		// ft_putendl("does not have pbie");
		return (FALSE);
	}
	play->player = ft_atoi(&line[2][1]);
	if (play->player == 1)
		play->symbol = 'o';
	else
		play->symbol = 'x';
	// ft_putstr("play->symbol is ");
	// ft_putchar(play->symbol);
	// ft_putendl("\n");
	part[0]++;
	return (TRUE);
}

void				parse_turn(t_play *play, int *part)
{
	char			*str;
	char			**line;
	t_bool		p_found;

	p_found = FALSE;
	while (ft_get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		// ft_putstr("line[0] is ");
		// ft_putendl(line[0]);
		if (!p_found && ft_strcmp(line[0], "$$$") == 0 && part[0] == 0)
		{
			if (parse_player(play, part, line))
			{
				// ft_putendl("p_found");
				p_found = TRUE;
			}
		}
		else if (p_found && ft_strcmp(line[0], "$$$") != 0 && (ft_strcmp(line[0], "Plateau") == 0
			|| (part[1] < play->plateau->y + 2 && ft_strcmp(line[0], "launched") != 0)))
			parse_plateau(play, part, line);
		else if (p_found && ft_strcmp(line[0], "$$$") != 0 && (ft_strcmp(line[0], "Piece") == 0
			|| (part[2] < play->piece->y + 1 && ft_strcmp(line[0], "launched") != 0)))
			parse_piece(play, part, line);
		// ft_putendl("freeing");
		free(line);
	}
}