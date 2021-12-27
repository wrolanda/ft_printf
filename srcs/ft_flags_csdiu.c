/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_csdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:07:46 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/28 02:38:27 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_c(t_print *tab)
{
	char	c;

	c = va_arg(tab->argptr, int);
	ft_putchar(c);
	return (1);
}

int	ft_flag_s(t_print *tab)
{
	char	*s;
	int		k;

	s = va_arg(tab->argptr, char *);
	k = ft_putstr(s);
	return (k);
}

int	ft_flag_di(t_print *tab, int i)
{
	int	numb;

	numb = va_arg(tab->argptr, int);
	i = ft_putnbr(numb);
	if (numb < 0)
		i++;
	return (i);
}
