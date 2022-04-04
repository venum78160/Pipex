/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:30:02 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/24 09:59:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t n)
{
	unsigned int	i;
	char			*new;

	new = (char *)s;
	c = (char) c;
	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (new[i] == c)
			return (new + i);
		i++;
		n--;
	}
	return (NULL);
}
