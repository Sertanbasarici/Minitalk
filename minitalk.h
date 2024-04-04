/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:28 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/04 13:31:23 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	message_reciever(int signal);
void	send_message(int pid, char c);
void	ft_print_error(void);

#endif