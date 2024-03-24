/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:40:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/24 00:36:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_BONUS_H
# define FT_SERVER_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	__fil_len(int *signum, int *c, int *i);
char	*add_char_to_string(char *str, char ch);
char	*ft_strcpy(char *dest, char *src);
#endif