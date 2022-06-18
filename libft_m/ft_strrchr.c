/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:00:05 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 03:58:14 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;
	char	*temp;

	i = 0;
	s = (char *)str;
	temp = NULL;
	if (c == 0)
		return (s + ft_strlen(str));
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = s + i;
		i++;
	}
	return (temp);
}
