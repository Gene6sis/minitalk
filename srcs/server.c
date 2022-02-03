/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:55:01 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/01 02:14:12 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static char	ft_btoc(char *str)
{
	int	c;
	int	i;
	int	power;

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

static void	ft_next(char **result, char **str)
{
	char		c;

	c = ft_btoc(*str);
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

static void	ft_signal(int signal)
{
	static char	*str;
	static int	count;
	static char	*result;

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
		ft_next(&result, &str);
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
}
