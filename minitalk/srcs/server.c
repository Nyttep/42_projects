/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:28 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 20:00:42 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*ft_handle_zero(char *ret, int *i)
{
	if (!ret)
		return (NULL);
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	(*i)++;
	if (ret && (*i) % 8 == 0 && ret[(*i) / 9] != 0)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + 2);
		if (!ret)
			ft_clean_exit("Error : Malloc failed", ret);
	}
	return (ret);
}

static char	*ft_handle_one(char *ret, int *i)
{
	if (!ret)
		return (NULL);
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	ret[(*i) / 8] = ret[(*i) / 8] + 0b00000001;
	(*i)++;
	if (ret && (*i) % 8 == 0 && ret[((*i) - 1) / 8] != 0)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + 2);
		if (!ret)
			ft_clean_exit("Error : Malloc failed", ret);
	}
	return (ret);
}

static char	*ft_new_client(int *i, char *ret, int *pid, siginfo_t *info)
{
	if (ret)
		free(ret);
	ft_bzero(ret = malloc(2), 2);
	*i = 0;
	*pid = info->si_pid;
	return (ret);
}

static void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static char	*ret = NULL;
	static int	i = 0;
	static int	pid = 0;

	(void) context;
	if (signum == SIGINT)
		ft_exit_sigint(ret);
	else if (signum == SIGQUIT)
		ft_exit_sigquit(ret);
	if (pid != info->si_pid)
		ret = ft_new_client(&i, ret, &pid, info);
	if (!ret)
		ft_clean_exit("Error : Malloc failed", ret);
	if (signum == SIGUSR1)
		ret = ft_handle_zero(ret, &i);
	else if (signum == SIGUSR2)
		ret = ft_handle_one(ret, &i);
	kill(pid, SIGUSR1);
	if (ret && ret[(i - 1) / 8] == 0 && i % 8 == 0)
	{
		ft_putstr_fd(ret, 1);
		free(ret);
		ret = NULL;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_bzero((void *)&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	ft_display_pid();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
