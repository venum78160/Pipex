/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:39:02 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:34:07 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*destination, const void	*source, size_t	size)
{
	char	*newdest;
	char	*newsource;
	int		i;

	i = 0;
	if (destination == NULL && source == NULL)
		return (0);
	newdest = (char *) destination;
	newsource = (char *) source;
	while (size > 0)
	{
		newdest[i] = newsource[i];
		i++;
		size--;
	}
	return (newdest);
}
