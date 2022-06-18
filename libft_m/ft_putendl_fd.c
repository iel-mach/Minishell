/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:32:18 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/13 23:50:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd (s, fd);
	write(fd, "\n", 1);
}

// int main()
// {
// 	int fd;
// 	fd = open("file.txt", O_RDWR);
// 	ft_putendl_fd("hamza",fd);
// }