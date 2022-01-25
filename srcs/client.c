/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:22:52 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/25 05:03:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_sendbit(int pid, char *message)
{
	char c;
	int i;
	int send;
	int err;

	err = 0;
	i = 0;
	while (message[i])
	{
		c = 0;
		send = c & 1 << (7 - i);
		if (send && !err)
			if (kill(pid, SIGUSR1) == -1)
				err = 1;
		if (!send && !err)
			if (kill(pid, SIGUSR2) == -1)
				err = 1;
	}

}

int ft_arg_error(char *nbr, char *str, int *pid, char **message)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	*pid = ft_atoi(nbr);
	*message = str;
	return (0);
}


int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	
	if (argc != 3 || ft_arg_error(argv[1], argv[2], &pid, &message))
	{
		ft_putstr_fd("client: invalid arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_sendbit(pid, message);
}
