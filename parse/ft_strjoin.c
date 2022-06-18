/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:06:21 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/17 03:56:58 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_s(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		a;
	int		b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	new = malloc ((a + b + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < a)
		new[i++] = s1[j++];
	j = 0;
	while (j < b)
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*new;
	int		i;
	int		a;

	a = ft_strlen(s1);
	new = malloc(a + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (i < a)
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = s2;
	new[i] = '\0';
	free (s1);
	return (new);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*x;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	x = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (0);
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		x[i] = s2[j];
		j++;
		i++;
	}
	x[i] = '\0';
	return (x);
}
