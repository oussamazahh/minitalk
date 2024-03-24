/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:39:59 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/24 00:36:25 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLIENT_BONUS_H
# define FT_CLIENT_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	signal_handler(int signum);
void	handler(int signum);

#endif