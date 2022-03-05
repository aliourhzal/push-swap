/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:49:56 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/28 12:52:00 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac < 2)
		return (0);
	prepare_stack(ac, av, &stack);
	if (stack_checker(stack.a, stack.lena))
		exit (1);
	if (stack.lena <= 3 || stack.lena <= 5)
		mini_sort(&stack);
	else
		indexing(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}


// int arr[] = {1,2,5,6};