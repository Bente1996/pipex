/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:22:40 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/20 11:16:35 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *print, ...);
size_t	handle_print(char flag, va_list args);
size_t	handle_char(char c);
size_t	handle_string(char *s);
size_t	handle_pointer(void *p);
size_t	handle_signed(int n);
size_t	handle_unsigned(unsigned int u);
size_t	handle_hexa_low(unsigned int x);
size_t	handle_hexa_up(unsigned int xx);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putaddress(void *p);
size_t	ft_hexalen(uintptr_t x);
void	ft_putnbr_signed(int n);
void	ft_putnbr_unsigned(unsigned int u);
void	ft_puthexa_low(unsigned int x);
void	ft_puthexa_up(unsigned int xx);

#endif