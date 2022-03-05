/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:11:19 by aourhzal          #+#    #+#             */
/*   Updated: 2022/02/20 19:45:33 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ms_n_over(int fd, char *over)
{
	char	buff;
	int		rc;

	rc = 1;
	buff = 0;
	while (buff != '\n' && rc != 0)
	{
		rc = read(fd, &buff, 1);
		if (buff == '\0')
			return (NULL);
		if (rc <= 0)
			return (NULL);
		over = ft_joinchr(over, buff);
	}
	return (over);
}

char	*get_next_line(int fd)
{
	char	*over;

	over = NULL;
	if (fd < 0)
		return (NULL);
	over = ms_n_over(fd, over);
	if (!over)
		return (NULL);
	return (over);
}
