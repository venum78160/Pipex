/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:36:18 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/28 12:12:26 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(char const *trim, const char str)
{
	int	i;

	i = 0;
	while (trim[i] != '\0')
	{
		if (trim[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (ft_test(set, s1[i]) == 1)
		i++;
	while (ft_test(set, s1[j - 1]) == 1)
		j--;
	if (j < i)
		j = i;
	new = ft_calloc(sizeof(char), (j - i + 1));
	if (!new)
		return (NULL);
	while (i < j)
		new[k++] = s1[i++];
	return (new);
}
