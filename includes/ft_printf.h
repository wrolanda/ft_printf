/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:10:06 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 23:33:53 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft.h"

typedef struct s_print
{
	va_list	argptr;
	int		tl;
	int		i;
}	t_print;
int		ft_printf(const char *str, ...);

int		ft_countnbr_hex(unsigned long int nmb);
void	ft_print_hex(unsigned long int x, char *mas);

int		ft_flag_c(t_print *tab, char s);
int		ft_flag_s(t_print *tab);
int		ft_flag_di(t_print *tab, int i);
int		ft_flag_u(t_print *tab, int i);
int		ft_flag_p(t_print *tab, char *mas);
int		ft_flag_xX(t_print *tab, char *mas);
int		ft_f_sh(t_print *tab, char *mas1, char *mas2, char s);
int		ft_flag_plus(t_print *tab);
int		ft_flag_space(t_print *tab);
int		ft_flag_s_space(t_print *tab);

#endif