/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:54:33 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/13 21:37:27 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <fcntl.h>

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;

	n = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		n = nb * -1;
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + 48), fd);
	}
	if (n < 10)
		ft_putchar_fd((n + 48), fd);
}

// int main()
// {
//     int fd;

//     fd = open("file.txt", O_WRONLY);
//     ft_putnbr_fd(45, fd);
// }