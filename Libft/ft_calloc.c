/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:03:09 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:29:47 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	Count, size_t	size)
{
	void	*pointeur;

	pointeur = malloc(Count * size);
	if (!pointeur)
		return (NULL);
	ft_bzero (pointeur, Count * size);
	return (pointeur);
}
