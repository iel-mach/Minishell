/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:21:40 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/16 16:12:08 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	*x;

	x = (unsigned char *)src;
	p = (unsigned char *)dst;
	i = 0;
	if (x == NULL && p == NULL)
		return (NULL);
	if (x == p)
		return (p);
	while (i < n)
	{
		p[i] = x[i];
		i++;
	}
	return (p);
}

// int main()
// {
//     char s[] = "hamza";
//     char d[] = "boukilihhh";
//     size_t e = 8;
//     ft_memcpy(d,s,e);
//     printf("%s",d);
//     char y[] = "hamza";
//     char u[] = "bk";
//     size_t k = 8;
//     memcpy(u,y,k);
//     printf("\ndyelhume:  %s",u);
// }
