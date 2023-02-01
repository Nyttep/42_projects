/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:34:28 by paul              #+#    #+#             */
/*   Updated: 2023/02/01 17:55:25 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		size_line;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		floor[3];
	int		ceiling[3];
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
}	t_game;

int		get_next_line(int fd);
int		ft_is_newline_gnl(char *s);
int		ft_strlen_gnl(char *s);
char	*ft_kinda_strcat_gnl(char *s, char *init);
void	ft_get_reste_gnl(char *s, char *reste, int read_return);
char	*ft_cpy_and_rst_reste_gnl(char *ret, char *reste);
void	ft_init_gnl(char **s, char **ret, int *read_return, char *reste);
void	ft_check(int ac, char **av);
void	ft_quit(t_game *game);
void	ft_error(t_game *game, char *s);
char	*ft_skip_spaces(char *s);
bool	ft_unfinished(int state[6]);

#endif