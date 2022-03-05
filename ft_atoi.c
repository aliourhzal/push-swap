/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:52:11 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:09:46 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str, int *a)
{
	int		i;
	long	intv;
	int		sign;

	i = -1;
	intv = 0;
	sign = 1;
	while (str[++i] == ' ')
		if (str[i + 1] == '\0')
			ft_error(a, "Error\n");
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			intv = intv * 10 + str[i++] - 48;
		else if (str[i] == ' ')
			break ;
		else
			ft_error(a, "Error\n");
	}
	return (intv * sign);
}
