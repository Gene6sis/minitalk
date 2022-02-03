/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:22:52 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/01 02:34:55 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(150);
	}
}

unsigned char	*ft_stob(char *str)
{
	int				i;
	int				j;
	unsigned char	*result;
	unsigned int	c;

	i = 0;
	result = ft_calloc(ft_strlen(str) * 8 + 9, sizeof(unsigned char *));
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

static unsigned char	*ft_addzero(unsigned char *message)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (message[i])
		i++;
	j = 0;
	while (j < 8)
	{
		message[i + j] = '0';
		j++;
	}
	return (message);
}

int	main(int argc, char **argv)
{
	unsigned char	*message;
	int				i;

	if (argc != 3)
	{
		ft_printf("client: invalid arguments.\n");
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9' || ft_atoi(argv[1]) <= 0)
			return (0);
		i++;
	}
	message = ft_stob(argv[2]);
	if (!message)
		return (0);
	message = ft_addzero(message);
	if (!message)
		return (0);
	ft_sendbit(ft_atoi(argv[1]), message);
	free(message);
	return (0);
}
