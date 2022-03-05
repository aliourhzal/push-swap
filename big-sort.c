/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:00:36 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/25 18:27:52 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	shift_counter(int stack_len)
{
	int	i;

	i = 1;
	if (stack_len >= 2)
		i++;
	if (stack_len >= 4)
		i++;
	if (stack_len >= 8)
		i++;
	if (stack_len >= 16)
		i++;
	if (stack_len >= 32)
		i++;
	if (stack_len >= 64)
		i++;
	if (stack_len >= 128)
		i++;
	if (stack_len >= 256)
		i++;
	if (stack_len >= 512)
		i++;
	return (i);
}

int	is_rev_sorted(int *stack, int len)
{
	if (len != 0)
	{
		if (len == 1)
			return (1);
		while (stack[len - 1] > stack[len - 2])
		{
			if (len - 2 == 0)
				return (1);
			len--;
		}
		return (0);
	}
	return (0);
}

void	ops_on_a(t_stack *stack, t_stack *index, int i)
{
	int	a;

	a = index->lena;
	while (a-- > 0)
	{
		if (index->a[index->lena - 1] & 1 << i)
		{
			rotate(index->a, index->lena, "ra\n");
			rotate(stack->a, stack->lena, NULL);
		}
		else if (!is_sorted(index->a, index->lena))
		{
			push_b(index, "pb\n");
			push_b(stack, NULL);
		}
	}
}

void	ops_on_b(t_stack *stack, t_stack *index, int i)
{
	int	a;

	a = index->lenb;
	while (a-- > 0)
	{
		if (!(index->b[index->lenb - 1] & 1 << (i + 1)))
		{
			if (!is_rev_sorted(index->b, index->lenb)
				|| !(index->b[index->lenb - 1] & 1 << (i + 1)))
			{
				rotate(index->b, index->lenb, "rb\n");
				rotate(stack->b, stack->lenb, NULL);
			}
		}
		else
		{
			push_a(index, "pa\n");
			push_a(stack, NULL);
		}
	}
}

void	big_sort(t_stack *stack, t_stack *index, int stack_len)
{
	int	left_shift;
	int	i;

	left_shift = shift_counter(stack_len);
	i = 0;
	while (i < left_shift)
	{
		ops_on_a(stack, index, i);
		ops_on_b(stack, index, i);
		i++;
	}
	while (index->lenb > 0)
	{
		push_a(index, "pa\n");
		push_a(stack, NULL);
	}
}

/*
2	0	00
4	2	10
3	1	01
5	3	11

a____*/

/*



b____*/