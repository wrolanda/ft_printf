/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:55:14 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 21:08:11 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_countnbr_hex(unsigned long int nmb)
{
	int	i;

	i = 1;
	while (nmb > 15)
	{
		nmb /= 16;
		i++;
	}
	return (i);
}

void	ft_print_hex(unsigned long int x, char *mas)
{
	if (x < 16)
		ft_putchar(mas[x]);
	else
	{
		ft_print_hex(x / 16, mas);
		ft_print_hex(x % 16, mas);
	}	
}

int	ft_flag_p(t_print *tab, char *mas)
{
	int					len;
	unsigned long int	x;

	x = va_arg(tab->argptr, unsigned long int);
	if (x == 0)
	{
		write(1, "(nil)", 5);
		tab->i = 1;
		return (5);
	}
	len = ft_countnbr_hex(x) + 2;
	ft_putstr("0x");
	ft_print_hex(x, mas);
	tab->i = 1;
	return (len);
}

int	ft_flag_xX(t_print *tab, char *mas)
{
	int				len;
	unsigned int	x;

	x = va_arg(tab->argptr, unsigned int);
	len = ft_countnbr_hex(x);
	ft_print_hex(x, mas);
	tab->i = 1;
	return (len);
}
