/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:40:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/08 17:47:13 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_BONUS_H
# define FT_SERVER_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

void	__fil_len(int *signum, int *c, int *i);
void	intializ_var(int *i, int *c, char *ch, int *j);
void	__check_pid(int si_pid, int arr[2], int *c, char *ch);
void	mysignal_handler(int signum, siginfo_t *info, void *context);
void	intializ_var(int *i, int *c, char *ch, int *j);
#endif