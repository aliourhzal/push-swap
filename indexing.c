/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:12:22 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:19:17 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexof(int *a, int len, int target)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (a[i] == target)
			return (i);
	}
	return (i);
}

void	indexing(t_stack *stack)
{
	int		*sorted;
	t_stack	index;
	int		i;
	int		sym;

	sorted = ft_sort_int_tab(stack->a, stack->lena);
	index.a = malloc(stack->lena * sizeof(int));
	if (!index.a || !sorted)
		ft_error(stack->a, NULL);
	index.lena = stack->lena;
	index.lenb = 0;
	i = -1;
	while (++i < stack->lena)
	{
		sym = indexof(stack->a, stack->lena, sorted[i]);
		index.a[sym] = i;
	}
	big_sort(stack, &index, i - 1);
	free(index.a);
	free(sorted);
}
