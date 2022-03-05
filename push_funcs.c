/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:39:06 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:27:44 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*len_m_one(int *stack, int *len)
{
	int	*new_stack;
	int	i;

	i = -1;
	*len -= 1;
	if (*len == 0)
	{
		free(stack);
		return (0);
	}
	new_stack = malloc((*len) * sizeof(int));
	if (!new_stack)
		exit (1);
	if (stack)
		while (++i < *len)
			new_stack[i] = stack[i];
	free(stack);
	return (new_stack);
}

int	*len_p_one(int *stack, int *len)
{
	int	*new_stack;
	int	i;

	i = -1;
	*len += 1;
	new_stack = malloc((*len) * sizeof(int));
	if (!new_stack)
		exit (1);
	if (*len == 1)
		return (new_stack);
	else
	{
		while (++i < *len)
			new_stack[i] = stack[i];
		free(stack);
	}
	return (new_stack);
}

void	push_b(t_stack *stack, char *op)
{
	if (stack->lena != 0)
	{
		stack->b = len_p_one(stack->b, &stack->lenb);
		stack->b[stack->lenb - 1] = stack->a[stack->lena - 1];
		stack->a = len_m_one(stack->a, &stack->lena);
		write(1, op, 3);
	}
}

void	push_a(t_stack *stack, char *op)
{
	if (stack->lenb != 0)
	{
		stack->a = len_p_one(stack->a, &stack->lena);
		stack->a[stack->lena - 1] = stack->b[stack->lenb - 1];
		stack->b = len_m_one(stack->b, &stack->lenb);
		write(1, op, 3);
	}
}
