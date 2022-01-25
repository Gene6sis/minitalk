/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:54:37 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 03:21:54 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printfar(const char *fmt, ...);
void	ft_putcharar(char c, int *val);
void	ft_putnbrar(int nb, int *val);
void	ft_putunbrar(unsigned int nb, int *val);
void	ft_putstrar(char *str, int *val);
void	ft_convertar(unsigned int nbr, int *i, int maj);
void	ft_pointerar(unsigned long int addr, int *i);
void	ft_base_hexar(unsigned long int nb, int *val);

#endif