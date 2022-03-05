/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:04 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/20 19:46:09 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *stack, int len, char *op)
{
	int	rep;

	rep = stack[len - 1];
	stack[len - 1] = stack[len - 2];
	stack[len - 2] = rep;
	write(1, op, 3);
}

void	rotate(int *stack, int len, char *op)
{
	int	rep;

	rep = stack[len - 1];
	while (len - 1 > 0)
	{
			stack[len - 1] = stack[len - 2];
			len--;
	}
	stack[len - 1] = rep;
	write(1, op, 3);
}

void	rev_rotate(int *stack, int len, char *op)
{
	int	i;
	int	rep;

	i = -1;
	rep = stack[0];
	while (++i < len)
		stack[i] = stack[i + 1];
	stack[i - 1] = rep;
	write(1, op, 4);
}
