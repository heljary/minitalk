/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:35:24 by heljary           #+#    #+#             */
/*   Updated: 2025/03/21 04:15:18 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				count_bit;
	static int				l_client;
	static unsigned char	c;

	(void)context;
	if (l_client != info->si_pid)
	{
		l_client = info->si_pid;
		c = 0;
		count_bit = 0;
	}
	if (sig == SIGUSR2)
		c |= (1 << count_bit);
	if (sig == SIGUSR1)
		c |= (0 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		if (c == '\0')
			kill(l_client, SIGUSR1);
		else
			ft_putchar(c);
		count_bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_putstr("PID SERVER : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putchar('\n');
	while (1)
	{
	}
	return (0);
}
