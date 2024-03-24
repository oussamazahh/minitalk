/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 06:57:13 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/23 14:25:26 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <stdarg.h>
# include <unistd.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	__fil_len(int *signum, int *c, int *i);
char	*add_char_to_string(char *str, char ch);
char	*ft_strcpy(char *dest, char *src);
#endif