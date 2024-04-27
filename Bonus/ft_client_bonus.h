/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:39:59 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/23 11:54:55 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLIENT_BONUS_H
# define FT_CLIENT_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

void	signal_handler(int signum);
void	handler(int signum);

#endif