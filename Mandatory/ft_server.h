/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 06:57:13 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 18:40:05 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

void	__fil_len(int *signum, int *c, int *i);
void	intializ_var(int *i, int *c, char *ch, int *j);
void	__check_pid(int si_pid, int arr[2], int *c, char *ch);
#endif