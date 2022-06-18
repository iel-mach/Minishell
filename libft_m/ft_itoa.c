/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 04:28:06 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/13 21:36:17 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(long int nbr, long int nb, int x, int j)
{
	char	*m;
	int		r;

	while (nb > 0)
	{
		nb = nb / 10;
		x++;
	}
	m = malloc((x + 1) * sizeof(char));
	if (!m)
		return (NULL);
	m[x] = '\0';
	x--;
	while (x >= 0)
	{
		r = nbr % 10;
		m[x--] = r + 48;
		nbr = nbr / 10;
	}
	if (j == 0)
		m[0] = '-';
	return (m);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	long int	nb;
	int			j;
	int			x;

	x = 0;
	j = 1;
	nb = n;
	nbr = nb;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		nb = nb * -1;
		nbr = nbr * -1;
		j--;
		x++;
	}
	return (ft_itoa2(nbr, nb, x, j));
}
