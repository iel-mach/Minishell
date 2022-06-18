/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:06:37 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/13 22:13:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)s1;
	if (!s || !set)
		return (NULL);
	if (!set)
		return (s);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s[i] && checker(s[i], set))
		i++;
	while (j > 0 && checker(s[j], set))
		j--;
	return (ft_substr(s, i, (j - i) + 1));
}
