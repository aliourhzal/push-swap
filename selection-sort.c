/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:25:28 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:19:49 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy(int *sorted, int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		sorted[i] = tab[i];
}

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*sorted;
	int	temp;

	i = -1;
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	cpy(sorted, tab, size);
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[j];
				sorted[j] = sorted[i];
				sorted[i] = temp;
			}
		}
	}
	return (sorted);
}
