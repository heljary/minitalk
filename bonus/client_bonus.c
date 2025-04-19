/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:37:16 by heljary           #+#    #+#             */
/*   Updated: 2025/03/21 05:43:04 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sa_hand(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("OK!\n");
	}
}

void	send_sig(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				error_exit("error to send signal 2 !");
				ft_putchar('\n');
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				error_exit("error to send signal 1 !");
				ft_putchar('\n');
			}
		}
		bit++;
		usleep(100);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	is_valid_number(char *str)
{
	int	i;
	int	digit_found;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	digit_found = 0;
	while (ft_isdigit(str[i]))
	{
		digit_found = 1;
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0' || !digit_found)
	{
		ft_putstr("Invalid argument.\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*message;

	signal(SIGUSR1, sa_hand);
	if (ac != 3)
	{
		ft_putstr("Error: ./b_client [server_pid] [message]\n");
		return (0);
	}
	i = 0;
	is_valid_number(av[1]);
	pid = ft_atoi(av[1]);
	message = av[2];
	if (pid <= 0)
		error_exit("Error: Invalid PID\n");
	while (message[i])
	{
		send_sig(pid, message[i]);
		i++;
	}
	send_sig(pid, '\0');
	return (0);
}
