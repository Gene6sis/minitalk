/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:53:14 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 03:19:58 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parameters(char c, va_list ap, int *i)
{
	if (c == 'c')
		return (ft_putcharar((char)va_arg(ap, int), i));
	else if (c == 's')
		return (ft_putstrar(va_arg(ap, char *), i));
	else if (c == 'p')
		return (ft_pointerar(va_arg(ap, unsigned long int), i));
	else if (c == 'd' || c == 'i')
		return (ft_putnbrar(va_arg(ap, int), i));
	else if (c == 'u')
		return (ft_putunbrar(va_arg(ap, unsigned int), i));
	else if (c == 'x')
		return (ft_convertar(va_arg(ap, unsigned int), i, 0));
	else if (c == 'X')
		return (ft_convertar(va_arg(ap, unsigned int), i, 1));
	else
		ft_putcharar('%', i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		x;

	i = 0;
	x = 0;
	va_start(ap, fmt);
	while (fmt[x])
	{
		if (fmt[x] == '%')
		{
			ft_parameters(fmt[x + 1], ap, &i);
			x += 2;
		}
		else
			ft_putcharar(fmt[x++], &i);
	}
	va_end(ap);
	return (i);
}
