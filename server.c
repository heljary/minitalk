/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:01:07 by heljary           #+#    #+#             */
/*   Updated: 2025/03/21 04:12:10 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		count_bit;
	static int		l_client;
	unsigned char	c;

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
		ft_putchar(c);
		c = 0;
		count_bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
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
