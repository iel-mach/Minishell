/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:51:20 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:53:56 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_opt(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (s[i] == '\0' || s[i] == ' ')
		return (0);
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	check_export2(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	check_export3(char *str)
{
	int	i;
	int	x;

	i = 0;
	while (g_f->old_env[i])
	{
		x = 0;
		while (g_f->old_env[i][x])
		{
			if (str[x] == g_f->old_env[i][x])
				x++;
			if (str[x] == '\0' && g_f->old_env[i][x] == '=')
				return (1);
			if (str[x] == '\0' && g_f->old_env[i][x] == '\0')
				return (1);
			if (str[x] != g_f->old_env[i][x])
				break ;
		}
		i++;
	}
	return (0);
}

int	check_unset2(char **str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (check_export2(str[i]))
		{
			if (check_export3(str[i]))
				c++;
		}
		i++;
	}
	return (c);
}

int	check_unset(char **str, char *s)
{
	int	i;
	int	x;

	i = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[i][x] == s[x])
				x++;
			if (str[i][x] == '\0' && s[x] == '=')
				return (-1);
			if (str[i][x] == '\0' && s[x] == '\0')
				return (-1);
			if (str[i][x] != s[x])
				break ;
		}
		i++;
	}
	return (-2);
}
