/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:45:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/25 04:18:52 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *s)
{
	if (game)
	{
		if (game->map)
			ft_free_strs(game->map);
		if (game->plyr)
			free(game->plyr);
		free(game);
	}
	if (s)	
		printf("Error : %s\n", s);
	else
		perror("Error ");
	exit(-1);
}