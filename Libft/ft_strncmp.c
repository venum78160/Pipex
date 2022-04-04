/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:14:17 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/23 18:36:41 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*first, const char	*second, size_t length)
{
	unsigned int	i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *) first;
	s = (unsigned char *) second;
	i = 0;
	if (length == 0)
		return (0);
	while (f[i] == s[i] && f[i] != '\0' && s[i] != '\0'
		&& i < length - 1)
		i++;
	return (f[i] - s[i]);
}
