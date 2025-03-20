/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:37:16 by heljary           #+#    #+#             */
/*   Updated: 2025/03/20 06:37:46 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h" 

void sa_hand(int sig)
{
    if(sig == SIGUSR1)
    {
        ft_putstr("OK !\n");
    }
}

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
        usleep(100);
    } 
}

int main(int ac,char **av)
{   
    signal(SIGUSR1, sa_hand);
    int i = 0;
    int pid = ft_atoi(av[1]);
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
    send_sig(pid, '\0');
    return 0;
}
