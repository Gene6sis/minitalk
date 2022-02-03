/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:55:01 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/01 01:55:31 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*ft_realloc(char *str, char c)
{
	char	*result;
	size_t	i;

	result = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	free(str);
	return (result);
}

static char	ft_btoc(char *str, int pidclient)
{
	int		c;
	int		i;
	int		j;
	int		power;

	c = 0;
	power = 1;
	i = ft_strlen(str) - 1;
	j = 0;
	while (j < 8)
	{
		c += (str[i] - '0') * power;
		i--;
		power *= 2;
		j++;
	}
	if (c == 0)
	{
		kill(pidclient, SIGUSR1);
		return ('\0');
	}
	return ((char)c);
}

void	ft_next(char **result, char **str, int pid)
{
	char		c;

	c = ft_btoc(*str, pid);
	*result = ft_realloc(*result, c);
	if (!*result)
		return ;
	if ((int)c == '\0')
	{
		ft_printf("%s", *result);
		free(*result);
		*result = NULL;
	}
	free(*str);
	*str = NULL;
}

void	ft_signal(int signal, siginfo_t *info, void *context)
{
	static char	*str;
	static int	count;
	static char	*result;

	(void)context;
	if (!result)
	{
		result = ft_calloc(1, sizeof(char));
		if (!result)
			return ;
	}
	if (!str)
	{
		str = ft_calloc(9, sizeof(char));
		if (!str)
			return ;
		count = 0;
	}
	count++;
	if (signal == SIGUSR1)
		str[count - 1] = '1';
	else
		str[count - 1] = '0';
	if (count % 8 == 0)
		ft_next(&result, &str, info->si_pid);
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
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
}
