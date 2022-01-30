/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:22:52 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/27 23:45:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_sendbit(int pid, unsigned char *message)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		if (message[i] == '1')
			kill(pid, SIGUSR1);
		else if (message[i] == '0')
			kill(pid, SIGUSR2);
		i++;
		usleep(1500);
	}
}

unsigned char	*ft_stob(char *str)
{
	int				i;
	int				j;
	unsigned char	*result;
	unsigned int	c;

	i = 0;
	result = ft_calloc(ft_strlen(str) * 8 + 1, sizeof(unsigned char *));
	if (!result)
		return (NULL);
	while (str[i])
	{
		c = (int)str[i];
		j = i * 8 + 7;
		while (j >= (i * 8))
		{
			if (c % 2 == 1)
				result[j] = '1';
			else
				result[j] = '0';
			c /= 2;
			j--;
		}
		i++;
	}
	return (result);
}

static int	ft_arg_error(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void ft_receive(int signal)
{
	(void)signal;
	ft_printf("received\n");
}

void ft_receivee (int signal)
{
	(void)signal;
	ft_printf("erreurmon gars\n");
}

int	main(int argc, char **argv)
{
	unsigned char	*message;

	if (argc != 3)
	{
		ft_printf("client: invalid arguments.\n");
		return (0);
	}
	if (ft_arg_error(argv[1]) || ft_atoi(argv[1]) == 0)
	{
		ft_printf("client: invalid pid.\n");
		return (0);
	}
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receivee);
	message = ft_stob(argv[2]);
	ft_sendbit(ft_atoi(argv[1]), message);
	free(message);
	return (0);
}
