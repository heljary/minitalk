/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:37:16 by heljary           #+#    #+#             */
/*   Updated: 2025/01/28 19:37:20 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h" 

void send_sig(int pid,char c)
{
    int bit = 0;
    while(bit < 8)
    {
        if(c & (1 << bit))
        {
            if(kill(pid, SIGUSR2) == -1)
            {
                error_exit("error to send signal 2 !");
                ft_putchar('\n');
            }
        }
        else
        {
            if(kill(pid, SIGUSR1) == -1)
            {
                error_exit("error to send signal 1 !");
                ft_putchar('\n');
            }
        }
        bit++;
        usleep(1);
    } 
}


int main(int ac,char **av)
{   

    int i = 0;
    int pid = ft_atoi(av[1]);
    ft_putnbr(getpid());
    // signal();
    char *message = av[2];
    if(ac <= 2)
    {
        ft_putstr("Error: ./client [server_pid] [message]\n");
    }
    else if(pid <= 0)
        error_exit("Error: Invalid PID\n");

    while(message[i])
    {
        send_sig(pid,message[i]);
        i++;
    }
    return 0;
}
