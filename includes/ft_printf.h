/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:10:06 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 16:44:48 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft.h"

typedef struct s_print
{
	va_list	argptr;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_print;
int	ft_printf(const char *str, ...);
int	ft_flag_c(t_print *tab);
int	ft_flag_s(t_print *tab);
int	ft_flag_di(t_print *tab, int i);
int	ft_flag_u(t_print *tab, int i);
int	ft_flag_p(t_print *tab, char *mas);

#endif