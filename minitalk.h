/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:01:47 by heljary           #+#    #+#             */
/*   Updated: 2025/03/19 00:39:24 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr(int n);
void    ft_putstr(char *str);
void	ft_putchar(char c);
long     ft_atoi(const char *str);
void    error_exit(char *msg);

#endif
