/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:44:38 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:28:16 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi( const char	*theString)
{
	int					i;
	long				num;
	int					neg;

	neg = 1;
	i = 0;
	num = 0;
	while (theString[i] == '\t' || theString[i] == '\n' || theString[i] == '\v'
		|| theString[i] == '\f' || theString[i] == '\r' || theString[i] == ' ')
		i++;
	if (theString[i] == '+' || theString[i] == '-')
	{
		if (theString[i] == '-')
			neg *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
		num = num * 10 + neg * (theString[i++] - '0');
	}
	return ((int) num);
}
