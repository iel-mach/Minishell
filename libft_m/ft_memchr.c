/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:53:28 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/16 15:42:02 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*strr;
	size_t			i;

	strr = (unsigned char *) s;
	c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (strr[i] == c)
		{
			return (&strr[i]);
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char a[] = "hamza boukiili";
// 	printf("%s\n",ft_memchr(a,'i',15));
// 	// printf("%d",memchr("1",0,2));
//  }
