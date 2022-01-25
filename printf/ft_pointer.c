/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:48:17 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 03:19:34 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base_hexar(unsigned long int nb, int *val)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb <= 15)
		ft_putcharar(base[nb % 16], val);
	if (nb > 15)
	{
		ft_base_hexar(nb / 16, val);
		ft_putcharar(base[nb % 16], val);
	}
}

void	ft_pointerar(unsigned long int addr, int *val)
{
	if (addr == 0)
	{
		ft_putstrar("0x0", val);
		return ;
	}
	ft_putstrar("0x", val);
	ft_base_hexar(addr, val);
}
