/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:13:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 03:20:19 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrar(char *str, int *val)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstrar("(null)", val);
		return ;
	}
	while (str[i])
		write(1, &str[i++], 1);
	*val = *val + i;
}
