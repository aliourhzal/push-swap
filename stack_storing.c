/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_storing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:23:33 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/21 20:47:48 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_checker(int *a, int lenght)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lenght)
	{
		j = i;
		while (++j < lenght)
			if (a[i] == a[j])
				ft_error(a, "Error\n");
	}
	if (is_sorted(a, lenght))
		return (1);
	return (0);
}

void	argument_checker(char **arg)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	while (arg[++j])
	{
		i = -1;
		count = 0;
		while (arg[j][++i])
			if (arg[j][i] >= '0' && arg[j][i] <= '9')
				count++;
		if (count == 0)
			ft_error(NULL, "Error\n");
	}
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	stack_storing(int len, t_stack *stack, char **midway2_0)
{
	int	i;

	i = -1;
	stack->lena = len;
	stack->lenb = 0;
	while (++i < len)
	{		
		if (ft_atoi(midway2_0[len - 1 - i], stack->a) > MAX_INT
			|| ft_atoi(midway2_0[len - 1 - i], stack->a) < MIN_INT)
			ft_error(stack->a, "Error\n");
		stack->a[i] = ft_atoi(midway2_0[len - 1 - i], stack->a);
	}
	ft_free(midway2_0);
}

void	prepare_stack(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*midway;
	char	**midway2_0;

	i = 0;
	midway = NULL;
	argument_checker(av);
	midway = ft_strdup(av[++i]);
	while (++i < ac)
		midway = ft_strjoin(midway, av[i]);
	midway2_0 = ft_split(midway, ' ');
	free(midway);
	if (!midway2_0)
		exit (1);
	i = 0;
	while (midway2_0[i])
		i++;
	stack->a = malloc(i * sizeof(int));
	if (!stack->a)
	{
		ft_free(midway2_0);
		exit(1);
	}
	stack_storing(i, stack, midway2_0);
}
/*
-36 15 1000000 23 0
0	3	4 2	 1
1000
i = 3
a = 0
index[len - 1] & 1 << a != 0
*/
/*


3	011
2	010
4	100
a_______*/

/*

1	001
0	000
b_______*/
