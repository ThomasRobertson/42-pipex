/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:04:22 by troberts          #+#    #+#             */
/*   Updated: 2022/07/11 16:16:09 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define LEN_CHAR 1
# define PRINTF_ERROR_CODE -1

/* ************************************************************************** */
/*                            HELPERS TO CONVERSION                           */
/* ************************************************************************** */

size_t			_ft_printf_u_nbrlen(size_t n, int base_lenght);
char			*_ft_printf_ft_uitoa(size_t n, int base_lenght);

/* ************************************************************************** */
/*                                 CONVERSION                                 */
/* ************************************************************************** */

int				_ft_printf_print_int(va_list args);
int				_ft_printf_print_char(va_list args);
int				_ft_printf_print_str(va_list args);
int				_ft_printf_print_unsigned(va_list args);
int				_ft_printf_print_lower_hex(va_list args);
int				_ft_printf_print_upper_hex(va_list args);
int				_ft_printf_print_ptr(va_list args);

#endif
