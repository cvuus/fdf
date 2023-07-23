/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosimavonuechtritz <cosimavonuechtritz@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:48:33 by cuechtri          #+#    #+#             */
/*   Updated: 2023/03/08 08:57:24 by cosimavonue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

//Utils
int		ft_printf_putchar_fd(char c, int fd);
int		ft_printf_putstr_fd(char *s, int fd);

//Printf Function
int		ft_printf(const char *input, ...);
int		ft_parsing(char *input, va_list args);
int		converter_2000(char c, va_list args);

//Conversions
int		conversion_p(va_list args);
int		conversion_c(va_list args);
int		conversion_s(va_list args);
int		conversion_id(va_list args);
int		conversion_ui(va_list args);
int		conversion_xx(va_list args, char c);

#endif