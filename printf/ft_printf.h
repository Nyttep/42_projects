/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:58:54 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 19:49:37 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(const char	*str);
void	ft_putchar(char c);
int		ft_c(int c);
int		ft_s(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_u(unsigned int nbr);
int		ft_putnbr_hexa_u(unsigned long int nbr);
int		ft_putnbr_hexa_maj_u(unsigned int nbr);
void	ft_find_format(const char *str, int i, int *j, va_list args);
int		ft_printf(const char *str, ...);

#endif
