/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:15:21 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/24 09:55:48 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*string, int searchedChar)
{
	int		i;
	char	*str;

	i = 0;
	searchedChar = (char) searchedChar;
	str = (char *) string;
	if (string[0] == '\0' && searchedChar == '\0')
		return (NULL);
	if (string[0] == '\0')
		return (NULL);
	if (searchedChar == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (str + i);
	}
	while (str[i] != '\0')
	{
		if (str[i] == searchedChar)
			return (str + i);
		i++;
	}
	return (NULL);
}
