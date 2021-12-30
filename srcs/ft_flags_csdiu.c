/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_csdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:07:46 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/30 17:37:02 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_c(t_print *tab, char s)
{
	char	c;

	if (s == '%')
	{
		ft_putchar(s);
		tab->i = 1;
		return (1);
	}
	c = va_arg(tab->argptr, int);
	ft_putchar(c);
	tab->i = 1;
	return (1);
}

int	ft_flag_s(t_print *tab)
{
	char	*s;
	int		k;

	s = va_arg(tab->argptr, char *);
	k = ft_putstr(s);
	tab->i = 1;
	return (k);
}

int	ft_flag_di(t_print *tab, int i)
{
	int	numb;

	numb = va_arg(tab->argptr, int);
	i = ft_putnbr(numb);
	tab->i = 1;
	return (i);
}

int	ft_flag_u(t_print *tab, int i)
{
	unsigned int	unmb;

	unmb = va_arg(tab->argptr, unsigned int);
	i = ft_putnbru(unmb);
	tab->i = 1;
	return (i);
}
