/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:38:26 by heljary           #+#    #+#             */
/*   Updated: 2025/01/28 19:38:41 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define _GNU_SOURCE
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr(int n);
void    ft_putstr(char *str);
void	ft_putchar(char c);
int     ft_atoi(const char *str);
void    error_exit(char *msg);

#endif
