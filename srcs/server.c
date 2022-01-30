/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:55:01 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/30 01:31:29 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char ft_btoc(char *str)
{
	int c;
	int i;
	int power;

	c = 0;
	power = 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		c += (str[i] - '0') * power;
		i--;
		power *= 2;
	}
	return ((char)c);
}

static void ft_signal(int signal)
{
	static char	*str;
	static int	count;

	if (!str)
	{
		str = ft_calloc(9, sizeof(char));
		count = 0;
	}
	count++;
	if (signal == SIGUSR1)
		str[count - 1] = '1';
	else
		str[count - 1] = '0';
	if (count == 8)
	{
		ft_printf("%c", ft_btoc(str));
		free(str);
		str = NULL;
	}
}

int main(void)
{
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
}
