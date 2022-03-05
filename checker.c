/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:31:38 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/20 18:17:59 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	while (to_find[++i])
	{
		if (to_find[i] != str[i])
			return (0);
	}
	if (str[i + 1])
		return (0);
	return (1);
}

void	filtering_part2(t_stack *stack, char *oper)
{
	if (ft_strstr(oper, "rr\n"))
	{
		rotate(stack->a, stack->lena, NULL);
		rotate(stack->b, stack->lenb, NULL);
	}
	else if (ft_strstr(oper, "rra\n"))
		rev_rotate(stack->a, stack->lena, NULL);
	else if (ft_strstr(oper, "rrb\n"))
		rev_rotate(stack->b, stack->lenb, NULL);
	else if (ft_strstr(oper, "rrr\n"))
	{
		rev_rotate(stack->a, stack->lena, NULL);
		rev_rotate(stack->b, stack->lenb, NULL);
	}
	else
		ft_error(stack->a, "Error\n");
}

void	filtering_part1(t_stack *stack, char *oper)
{
	if (ft_strstr(oper, "sa\n"))
		ft_swap(stack->a, stack->lena, NULL);
	else if (ft_strstr(oper, "sb\n"))
		ft_swap(stack->b, stack->lenb, NULL);
	else if (ft_strstr(oper, "ss\n"))
	{
		ft_swap(stack->a, stack->lena, NULL);
		ft_swap(stack->b, stack->lenb, NULL);
	}
	else if (ft_strstr(oper, "pa\n"))
		push_a(stack, NULL);
	else if (ft_strstr(oper, "pb\n"))
		push_b(stack, NULL);
	else if (ft_strstr(oper, "ra\n"))
		rotate(stack->a, stack->lena, NULL);
	else if (ft_strstr(oper, "rb\n"))
		rotate(stack->b, stack->lenb, NULL);
	else
		filtering_part2(stack, oper);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*oper;

	if (ac < 1)
		return (0);
	prepare_stack(ac, av, &stack);
	stack_checker(stack.a, stack.lena);
	oper = get_next_line(0);
	while (1)
	{
		if (!oper)
			break ;
		filtering_part1(&stack, oper);
		free(oper);
		oper = get_next_line(0);
	}
	if (is_sorted(stack.a, stack.lena) && stack.lenb == 0)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	free(stack.a);
}
