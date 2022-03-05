/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:24:12 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/13 17:15:51 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nn)
{
	if (nn >= 10)
	{
		ft_putnbr(nn / 10);
		ft_putnbr(nn % 10);
	}
	else
	{
		ft_putchar(nn + 48);
	}
}
