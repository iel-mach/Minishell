/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:58:07 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/17 02:57:16 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*m;
	int		l;
	char	*x;

	if (!s || !f)
		return (NULL);
	i = 0;
	x = (char *)s;
	l = ft_strlen(s);
	m = malloc(l + 1);
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = f(i, x[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
