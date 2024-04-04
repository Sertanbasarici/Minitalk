/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:13 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/04 19:56:43 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	send_message(int pid, char c)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		if ((c >> index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(200);
	}
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argn, char **argv)
{
	int		i;
	char	*s;
	int		pid;

	if (argn == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_print_error();
		s = argv[2];
		i = 0;
		while (s[i])
		{
			send_message(pid, s[i]);
			i++;
		}
	}
	else
		ft_print_error();
}
