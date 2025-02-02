/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:01:07 by heljary           #+#    #+#             */
/*   Updated: 2025/01/27 13:01:13 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

unsigned char c;

void signal_handler(int sig)
{
    
    static int count_bit;

    if(sig == SIGUSR2)
    {
        c |= ( 1 << count_bit);
    }
    if(sig == SIGUSR1)
    {
        c |= ( 0 << count_bit);
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
    sa.sa_handler = signal_handler;
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