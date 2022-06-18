/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:16:06 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 06:47:19 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	if (!str)
		return (NULL);
	c = (unsigned char)c;
	i = 0;
	if (c == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		if (str[i] != '\0')
			i++;
	}
	return (NULL);
}
