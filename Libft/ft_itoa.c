/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:53:34 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/12/08 14:50:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	static char	res[13];
	int			neg;

	i = 13;
	res[--i] = '\0';
	neg = 0;
	if (n < 0)
		neg = 1;
	else
		n = -n;
	while (1)
	{
		res[--i] = '0' - n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	if (neg)
		res[--i] = '-';
	return (res + i);
}
