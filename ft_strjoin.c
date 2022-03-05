/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:17:30 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/20 17:05:42 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char	*ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = malloc((len + ft_strlen(s2)) * sizeof(char) + 2);
	if (str == NULL)
	{
		free(s1);
		exit (1);
	}
	i = -1;
	c = 0;
	while (++i < len)
		str[i] = s1[i];
	str[i] = ' ';
	while (c < ft_strlen(s2))
		str[++i] = s2[c++];
	str[++i] = '\0';
	free(s1);
	return (str);
}
