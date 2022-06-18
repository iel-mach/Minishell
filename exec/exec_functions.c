/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:56:32 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:54:01 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_export(char *str, char **old_env, int n)
{
	int	x;
	int	i;

	x = 0;
	while (x < n)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == old_env[x][i])
				i++;
			if (str[i] == '=' && old_env[x][i] == '=')
				return (x);
			if (str[i] == '=' && old_env[x][i] == '\0')
				return (x);
			if (str[i] == '\0' && old_env[x][i] == '=')
				return (-2);
			if (str[i] == '\0' && old_env[x][i] == '\0')
				return (x);
			if (str[i] != old_env[x][i])
				break ;
		}
		x++;
	}
	return (-1);
}

int	count_tusawi(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	cmd_pwd(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == 'p' || str[i] == 'P')
	{
		i++;
		if (str[i] == 'w' || str[i] == 'W')
		{
			i++;
			if (str[i] == 'd' || str[i] == 'D')
				return (1);
		}
	}
	return (0);
}

int	cmd_echo(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == 'e' || str[i] == 'E')
	{
		if (str[i + 1] == 'c' || str[i + 1] == 'C')
		{
			if (str[i + 2] == 'h' || str[i + 2] == 'H')
			{
				if (str[i + 3] == 'o' || str[i + 3] == 'O')
					return (1);
			}
		}
	}
	return (0);
}

int	cmd_env(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		if (str[i] == 'n' || str[i] == 'N')
		{
			i++;
			if (str[i] == 'v' || str[i] == 'V')
				return (1);
		}
	}
	return (0);
}
