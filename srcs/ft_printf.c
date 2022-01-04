/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:09:24 by wrolanda          #+#    #+#             */
/*   Updated: 2022/01/04 21:54:53 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->i = 0;
	tab->tl = 0;
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
	if (str[i] == ' ' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		k = ft_flag_space(tab);
	if (str[i] == ' ' && str[i + 1] == 's')
		k = ft_flag_s_space(tab);
	if (str[i] == '\0')
	{
		tab->i = 0;
		tab->tl = -1;
		return (0);
	}
	return (k);
}

int	ft_eval_str(t_print *tab, const char *str, int i)
{
	int	k;

	k = 0;
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
		k = ft_flag_lux(tab, "0123456789abcdef");
	else if (str[i] == 'X')
		k = ft_flag_lux(tab, "0123456789ABCDEF");
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
	while (str[++i])
	{
		if (str[i] == '%')
		{
			tab->tl += ft_eval_str(tab, str, i + 1);
			i += tab->i;
		}
		else
			tab->tl += write(1, &str[i], 1);
	}
	va_end(tab->argptr);
	ret = tab->tl;
	free (tab);
	return (ret);
}
