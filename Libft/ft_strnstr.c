/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:42:26 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/27 22:05:19 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*s1, const char	*s2, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	str = (char *) s1;
	if ((s1[0] == '\0' && s2[0] == '\0') || s2[0] == '\0')
		return (str);
	if (s1[0] == '\0')
		return (NULL);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) < len)
		{
			if (s2[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
