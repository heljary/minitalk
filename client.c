/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:00:01 by heljary           #+#    #+#             */
/*   Updated: 2025/03/20 02:15:43 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h" 

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

    int i = 0;
    int pid = ft_atoi(av[1]);
    
    char *message = av[2];
    if(ac <= 2)
        ft_putstr("Error: ./client [server_pid] [message]\n");
    else if(pid <= 0)
        error_exit("Error: Invalid PID\n");
    while(message[i])
    {
        send_sig(pid,message[i]);
        i++;
    }
    return 0;
}