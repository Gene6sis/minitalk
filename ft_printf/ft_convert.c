/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:18:39 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 05:02:46 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexar(unsigned int nb, int *val, char *base)
{
	unsigned long int	nbr;
	int					length;
	unsigned long int	cpy;

	length = 1;
	nbr = nb;
	cpy = nbr;
	while (cpy >= 16)
	{
		cpy /= 16;
		length++;
	}
	if (nbr >= 16)
		ft_puthexar(nbr / 16, val, base);
	ft_putcharar(base[nbr % 16], val);
}

void	ft_convertar(unsigned int nbr, int *val, int maj)
{
	if (maj == 0)
		ft_puthexar(nbr, val, "0123456789abcdef");
	else
		ft_puthexar(nbr, val, "0123456789ABCDEF");
}
