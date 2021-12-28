/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:17:28 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/28 13:20:26 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_countnbr(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	k;

	k = ft_countnbr((long int)n);
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n = -n;
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	return (k);
}

/*#include <stdio.h>
int	main(void)
{
	int	i =  -2147483648;
	int k = 0;
	k = ft_putnbr(i);
	printf("\n\n%d", k);	
}*/
