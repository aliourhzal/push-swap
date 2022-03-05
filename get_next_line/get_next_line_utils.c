/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:11:30 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/19 17:32:37 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* strchr starts here */

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

/* strchr ends here */

/* strjoin starts here */

char	*ft_joinchr(char *s1, char s2)
{
	int		i;
	int		c;
	char	*str;
	int		len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (++i < len)
		str[i] = s1[i];
	str[i++] = s2;
	str[i] = '\0';
	free(s1);
	return (str);
}

/* strjoin ends here */
