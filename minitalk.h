#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void    ft_putnbr(int n);
void    ft_putstr(char *str);
int     ft_atoi(const char *str);
void    error_exit(char *msg);
void    send_signal(int pid, char c);
void    confirm_signal(int sig);

#endif