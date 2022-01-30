/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:55:01 by adben-mc          #+#    #+#             */
/*   Updated: 2022/01/30 04:50:05 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	ft_btoc(char *str, int pidclient)
{
	int		c;
	int		i;
	int		power;

	c = 0;
	power = 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		c += (str[i] - '0') * power;
		i--;
		power *= 2;
	}
	if (c == 0)
		kill(pidclient, SIGUSR1);
	return ((char)c);
}

void	ft_signal(int signal, siginfo_t *info, void *context)
{
	static char	*str;
	static int	count;

	(void)context;
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
		ft_printf("%c", ft_btoc(str, info->si_pid));
		free(str);
		str = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = set;
	sa_signal.sa_sigaction = ft_signal;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("PIB : %d\n", getpid());
	while (1)
		pause();
}
