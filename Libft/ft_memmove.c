/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:47:01 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:35:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*destination, const void	*source, size_t	size )
{
	char		*newdest;
	char		*newsource;
	size_t		i;

	i = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	newdest = (char *) destination;
	newsource = (char *) source;
	if (newdest > newsource)
		while (size-- > 0)
			newdest[size] = newsource[size];
	else
	{
		while (size > 0)
		{
			newdest[i] = newsource[i];
			i++;
			size--;
		}
	}
	return (newdest);
}
