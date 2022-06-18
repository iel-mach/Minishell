/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:08:27 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/07 21:25:52 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;

	new = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	return (str);
}
// int main()
// {
//     // char a[] =  "abaaaadaasa";
//     // int c = '*';
//     // size_t n = 20;
//     // char *k = memset(a, c, n);
//     // printf("%s",k);
//     char p[] = "hamza";
//     int x = '*';
//     size_t m = 20;
//     char *b = ft_memset(p,x,m);
//     printf("\ndyelhume : %s",b);
// }
//  int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str + 9, '.', 4);
//     printf("After memset():  %s", str);
//     memset(str + 9, '.', 4);
//     printf("\nAfter2 memset():  %s", str);
//     return 0;
// }  
