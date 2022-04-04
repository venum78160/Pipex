/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:15:35 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 10:17:03 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		taill;
	char	*cpy;

	taill = 0;
	while (src[taill])
		taill++;
	cpy = (void *)malloc(sizeof(*cpy) * (taill + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < taill)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
