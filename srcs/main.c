/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:01:00 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/29 18:26:24 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		i = 1;
	int		k, m = 0;

	k = ft_printf(" %x ", LONG_MAX);
	m = printf(" %x ", LONG_MAX);

	printf("\n%d\n", k);
	printf ("%d\n", m);
	return (0);
}
