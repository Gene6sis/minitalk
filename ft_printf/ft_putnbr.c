/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:08:24 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 03:20:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrar(int nb, int *val)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putcharar('-', val);
		nbr *= -1;
	}
	if (nbr <= 9 && nbr >= 0)
	{
		ft_putcharar(nbr + '0', val);
	}
	if (nbr > 9)
	{
		ft_putnbrar(nbr / 10, val);
		ft_putcharar(nbr % 10 + '0', val);
	}
}
