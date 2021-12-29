/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:46:28 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 17:00:30 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

/*int	main(void)
{
	int	i1 = 0;
	//int	i2 = 0;
	char	*res;
	
	while (i1++ < 10)
	{
		res = ft_itoa(i1);
		write (1, &res[0], 1);
	}
}*/
