/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:15:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/05 19:30:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_strslen(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_strsjoin(char **s2, char **s1)
{
	char	**ret;
	int		k;
	int		i;

	k = -1;
	if (!s2)
		return (s1);
	ret = malloc (sizeof(char *) * (ft_strslen(s1) + ft_strslen(s2)+ 1));
	while (s1[++k])
	{
		ret[k] = ft_strdup(s1[k]);
		if (!ret[k])
			return (ft_free_strs(ret));
	}
	i = -1;
	while (s2[++i])
	{
		ret[k + i] = ft_strdup(s2[i]);
		if (!ret[k + i])
			return (ft_free_strs(ret));
	}
	ret[k + i] = NULL;
	ft_free_strs(s1);
	ft_free_strs(s2);
	return (ret);
}

long long int	ft_long_atoi(const char *str)
{
	int	i;
	long long int	neg;
	long long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * neg);
}

int ft_check_digit(int argc, char**argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit((int) argv[i][j]) && argv[i][j] != ' ')
				return (0);
	}
	return(1);
}

int	ft_check_intmax(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		if (ft_long_atoi(s[i++]) > 2147483647)
			return (0);
	return (1);
}

int	ft_check_duplicate(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		while(s[j])
		{
			if (ft_strcmp(s[i], s[j]) == 0)
				return (0);
			j++;
		}
		j = ++i + 1;
	}
	return (1);
}

int	ft_check(int argc, char **argv)
{
	char	**s;

	s = NULL;
	
	if (!ft_check_digit(argc, argv))
		return (0);
	while (--argc > 0)
	{
		s = ft_strsjoin(s, ft_split(argv[argc], ' '));
		if (!s)
			return (ft_free_strs(s), 0);
	}
	if (!ft_check_intmax(s))
		return (0);
	if (!ft_check_duplicate(s))
		return (0);
	ft_free_strs(s);
	return (1);
}