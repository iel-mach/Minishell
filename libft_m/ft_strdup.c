/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:55:00 by hboukili          #+#    #+#             */
/*   Updated: 2022/04/11 05:13:52 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;
	int		x;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	ptr = malloc (len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	x = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	s1 = ptr;
	return (s1);
}
