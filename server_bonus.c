/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:35:24 by heljary           #+#    #+#             */
/*   Updated: 2025/01/28 19:35:46 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char c;

void signal_handler(int sig, siginfo_t *info,void *context)
{
    static int count_bit;
    static int cl_pid = 0;
    cl_pid = info->si_pid;

    if(sig == SIGUSR2 && kill(cl_pid,SIGUSR1))
    {
        c |= ( 1 << count_bit);
        printf("message reciever by : [%d]\n",SIGUSR1);
    }
    if(sig == SIGUSR1 && kill(cl_pid,SIGUSR2))
    {
        c |= ( 0 << count_bit);
        printf("message reciever by : [%d]\n",SIGUSR2);
    }
    count_bit ++;
    if(count_bit == 8)
    {
        ft_putchar(c);
        c = 0;
        count_bit = 0;
    }
    
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    ft_putstr("PID SERVER : ");
    ft_putnbr(getpid());
    ft_putchar('\n');
    sigaction(SIGUSR1, &sa,NULL);
    sigaction(SIGUSR2, &sa,NULL);
    ft_putchar('\n');
    while (1)
    {}
    return 0;

}
