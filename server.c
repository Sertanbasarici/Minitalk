/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:23 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/04 13:28:42 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_reciever(int signal)
{
	static char		i = 0;
	static int		c = 0;

	if (signal == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, message_reciever);
	signal(SIGUSR2, message_reciever);
	ft_printf("PID number of the signal is %d", getpid());
	while (1)
		pause();
	return (0);
}
