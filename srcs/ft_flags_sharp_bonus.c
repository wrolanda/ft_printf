/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sharp_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:58:03 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 23:16:40 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_f_sh(t_print *tab, char *mas1, char *mas2, char s)
{
	int				len;
	unsigned int	x;

	x = va_arg(tab->argptr, unsigned int);
	tab->i = 2;
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
	len = ft_countnbr_hex(x) + 2;
	if (s == 'x')
	{
		ft_putstr("0x");
		ft_print_hex(x, mas1);
	}
	if (s == 'X')
	{
		ft_putstr("0X");
		ft_print_hex(x, mas2);
	}
	return (len);
}

int	ft_flag_plus(t_print *tab)
{
	int	numb;
	int	i;

	i = 0;
	numb = va_arg(tab->argptr, int);
	tab->i = 2;
	if (numb >= 0)
		i = ft_putchar('+');
	i += ft_putnbr(numb);
	return (i);
}

int	ft_flag_space(t_print *tab)
{
	int	numb;
	int	i;

	i = 0;
	numb = va_arg(tab->argptr, int);
	tab->i = 2;
	if (numb >= 0)
		i = ft_putchar(' ');
	i += ft_putnbr(numb);
	return (i);
}
