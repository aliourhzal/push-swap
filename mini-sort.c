/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:36:47 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/20 16:57:48 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	probability_three(t_stack *stack)
{
	int	i;

	i = 1;
	while (i != 0)
	{
		i = 0;
		if (stack->a[0] < stack->a[1])
		{
			rev_rotate(stack->a, 3, "rra\n");
			i++;
		}
		if (stack->a[0] < stack->a[2])
		{
			rotate(stack->a, 3, "ra\n");
			i++;
		}
		if (stack->a[1] < stack->a[2])
		{
			ft_swap(stack->a, 3, "sa\n");
			i++;
		}
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->lena == 2 && !is_sorted(stack->a, 2))
		ft_swap(stack->a, 2, "sa\n");
	else if (stack->lena > 2)
		probability_three(stack);
}

void	probability_five(t_stack *stack, int i)
{
	if (i < 2)
	{
		if (i == 1)
		{
			rev_rotate(stack->a, stack->lena, "rra\n");
			rev_rotate(stack->a, stack->lena, "rra\n");
		}
		else
			rev_rotate(stack->a, stack->lena, "rra\n");
	}
	else
	{
		if ((i == 2 && stack->lena == 4) || i == 3)
			rotate(stack->a, stack->lena, "ra\n");
		else
		{
			rotate(stack->a, stack->lena, "ra\n");
			rotate(stack->a, stack->lena, "ra\n");
		}
	}
}

void	sort_five(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = ft_sort_int_tab(stack->a, stack->lena);
	i = -1;
	j = 0;
	while (++i < stack->lena && j <= 1)
	{
		if (sorted[j] == stack->a[i])
		{
			if (i != stack->lena - 1)
				probability_five(stack, i);
			push_b(stack, "pb\n");
			j++;
			i = -1;
		}
	}
	sort_three(stack);
	push_a(stack, "pa\n");
	push_a(stack, "pa\n");
}

void	mini_sort(t_stack *stack)
{
	if (stack->lena <= 3)
		sort_three(stack);
	else if (stack->lena <= 5)
		sort_five(stack);
}
