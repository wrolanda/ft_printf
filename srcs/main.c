/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:01:00 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/28 13:18:15 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*p = NULL;
	int		i = -1;
	int		k, m = 0;

	k = ft_printf(" %d ", i);
	m = printf(" %d ", i);

	printf("\n%d\n", k);
	printf ("%d\n", m);
	return (0);
}
