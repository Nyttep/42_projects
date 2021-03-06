/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:08:05 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:27:23 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "libft.h"

void	ft_display_pid(void);
void	ft_exit_sigint(char *s);
void	ft_exit_sigquit(char *s);
void	ft_clean_exit(char *msg, char *s);

#endif