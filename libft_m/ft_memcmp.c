/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:18:57 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/07 21:16:16 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x1;
	unsigned char	*x2;
	size_t			i;

	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (x1[i] == x2[i] && i < n - 1)
		i++;
	return (x1[i] - x2[i]);
}
//  int main()z
//  {
// 	 printf("%d\n",ft_memcmp("AB","ZB",3));
// 	 printf("%d",memcmp("AZ","ZZ",3));	 
//  }
