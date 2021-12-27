/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:09:24 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/28 02:32:13 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_eval_str(t_print *tab, const char *str, int i)
{
	int	k;

	k = 0;
	if (str[i] == 'c')
		k = ft_flag_c(tab);
	else if (str[i] == 's')
		k = ft_flag_s(tab);
	else if (str[i] == 'd' || str[i] == 'i')
		k = ft_flag_di(tab, i);
	return (k);
}

int	ft_printf(const char *str, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->argptr, str);
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ret += ft_eval_str(tab, str, i + 1);
			i++;
		}
		else
			ret += write(1, &str[i], 1);
	}
	va_end(tab->argptr);
	ret += tab->tl;
	free (tab);
	return (ret);
}

/*#include <stdio.h>
int	main(void)
{
	int i;

	i = ft_printf("hello %s", "shura");
	ft_printf("\nlen = %d\n", i);
	i = printf("hello %s", "shura");
	printf("\nlen = %d\n", i);
	printf("\n");

	i = ft_printf("hello %c", 's');
	printf("\nlen = %d\n", i);
	i = printf("hello %c", 's');
	printf("\nlen = %d\n", i);
}*/

/*int	ft_printf(const char *str, ...)
{
	va_list			argptr;
	char			*name;
	unsigned int	days;

	va_start(argptr, str);
	name = va_arg(argptr, char *);
	days = va_arg(argptr, unsigned int);
	ft_putstr(name);
	ft_putnbr(days);
	va_end(argptr);
	return (0);
}

int	main(void)
{
	ft_printf("hello %s, you have %u days left", "shura", 10);
}*/