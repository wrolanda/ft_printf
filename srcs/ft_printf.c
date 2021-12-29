/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:09:24 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 22:51:07 by wrolanda         ###   ########.fr       */
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
	tab->i = 0;
	return (tab);
}

int	ft_bonus_eval(t_print *tab, const char *str, int i)
{
	int	k;

	k = 0;
	if (str[i] == '#' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		k = ft_f_sh(tab, "0123456789abcdef", "0123456789ABCDEF", str[i + 1]);
	if (str[i] == '+' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		k = ft_flag_plus(tab);
	return (k);
}

int	ft_eval_str(t_print *tab, const char *str, int i)
{
	int	k;

	k = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == 'c')
		k = ft_flag_c(tab, str[i]);
	else if (str[i] == 's')
		k = ft_flag_s(tab);
	else if (str[i] == 'd' || str[i] == 'i')
		k = ft_flag_di(tab, i);
	else if (str[i] == 'u')
		k = ft_flag_u(tab, i);
	else if (str[i] == 'p')
		k = ft_flag_p(tab, "0123456789abcdef");
	else if (str[i] == 'x')
		k = ft_flag_xX(tab, "0123456789abcdef");
	else if (str[i] == 'X')
		k = ft_flag_xX(tab, "0123456789ABCDEF");
	else if (str[i] == '%')
		k = ft_flag_c(tab, str[i]);
	else
		k = ft_bonus_eval(tab, str, i);
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
			i += tab->i;
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
