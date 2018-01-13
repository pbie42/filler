/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2018/01/13 15:54:04 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define TRUE 1
# define FALSE 0
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BWHITE "\033[1;97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define BRED "\033[1;31m"
# define GREEN "\033[32m"
# define BGREEN "\033[1;32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BMAGENTA "\033[1;35m"
# define CYAN "\033[36m"
# define BCYAN "\033[1;36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[1;46m"
# define BGLIGHT "\033[1;47m"
# define BGGRAY "\033[47m"
# define INVWHITE "\033[7;97m"
# define INVCYAN "\033[7;36m"
# define INVRED "\033[7;31m"
# define INVMAGENTA "\033[7;35m"

# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <ftw.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <termios.h>
# include <err.h>
# include <termcap.h>
# include "../libft/includes/libftprintf.h"
# include <term.h>

typedef int			t_bool;

typedef struct		s_plateau
{
	int				x;
	int				y;
	char			**board;
}					t_plateau;

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

typedef struct		s_territory
{
	t_coords		*top;
	t_coords		*bottom;
	t_coords		*left;
	t_coords		*right;
}					t_territory;

typedef struct		s_piece
{
	int				x;
	int				y;
	t_territory		*terr;
	char			**real;
	char			**piece;
}					t_piece;

typedef struct		s_direction
{
	t_bool			up;
	t_bool			down;
	t_bool			left;
	t_bool			right;
}					t_direction;

typedef struct		s_play
{
	t_plateau		*plateau;
	t_piece			*piece;
	t_territory		*territory;
	t_territory		*enemy;
	t_direction		*dir;
	char			symbol;
	char			e_symbol;
	int				player;
	int				x;
	int				y;
}					t_play;

int				parse_turn(t_play *play, int *part);
void				find_territory(t_play *play);
void				find_enemy(t_play *play);
int					place_piece(t_play *play);
t_bool				piece_right(t_play *play);
t_bool				piece_left(t_play *play);
t_bool				piece_up(t_play *play);
t_bool				piece_down(t_play *play);
int					piece_down_right(t_play *play);
int					piece_down_left(t_play *play);
int					piece_up_left(t_play *play);
int					piece_up_right(t_play *play);
t_bool				can_place(t_play *play, int x, int y);
int					compare_coords(t_play *play, int x, int y, char *str);
int					ft_strhas(const char *s1, const char *s2);
void				setup_turn(t_play *play, int *part);
void				find_piece(t_play *play);
int					down_priority(t_play *play);
int					up_priority(t_play *play);
int					left_priority(t_play *play);
int					right_priority(t_play *play);
t_bool				place_anywhere(t_play *play);
void				enemy_setup(t_play *play);
void				malloc_real(t_play *play);
void				free_play(t_play *play);
void				free_board(t_play *play);
void				free_piece(t_play *play);
void				free_real_piece(t_play *play);

#endif
