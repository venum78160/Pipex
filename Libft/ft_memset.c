/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:28:56 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:35:23 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *pointeur, int value, size_t count)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *) pointeur;
	while (count > 0)
	{
		new[i++] = value;
		count--;
	}
	return (new);
}
