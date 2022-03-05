/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:10:08 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:08:02 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *a, char *msg)
{
	free(a);
	write(1, msg, 7);
	exit(1);
}

int	is_sorted(int *stack, int len)
{
	if (len == 1)
		return (1);
	while (stack[len - 1] < stack[len - 2])
	{
		if (len - 2 == 0)
			return (1);
		len--;
	}
	return (0);
}
