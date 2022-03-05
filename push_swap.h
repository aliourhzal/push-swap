/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:52:29 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/21 12:01:00 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	lena;
	int	lenb;
}	t_stack;

long	ft_atoi(const char *nptr, int *a);
void	ft_error(int *a, char *msg);
void	indexing(t_stack *stack);
int		*ft_sort_int_tab(int *tab, int size);
void	push_b(t_stack *stack, char *op);
void	push_a(t_stack *stack, char *op);
void	rotate(int *stack, int len, char *op);
void	rev_rotate(int *stack, int len, char *op);
void	ft_swap(int *stack, int len, char *op);
void	big_sort(t_stack *stack, t_stack *index, int stack_len);
void	mini_sort(t_stack *stack);
void	ft_putnbr(long nn);
int		is_sorted(int *stack, int len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);
void	prepare_stack(int ac, char **av, t_stack *stack);
int		stack_checker(int *a, int lenght);

#endif
