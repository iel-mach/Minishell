/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:43:41 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 05:45:43 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_function3(t_parser *cmd, int i, long long x)
{
	if (i == 1)
		printf("exit\n");
	x = ft_atoi(*cmd->arg);
	if (x == -1)
	{
		printf("bash: exit: %s: numeric argument required\n", cmd->arg[0]);
		return (255);
	}
	else
	{
		if (x > 255)
			x %= 256;
		if (x == 2)
			g_f->a = 2;
		if (x == 3)
			g_f->a = 3;
	}
	return (x);
}

int	exit_function2(t_parser *cmd, int i, long long x)
{
	int	n;

	if (ft_isalpha(cmd->arg[0][0]) || ft_check_digit(cmd->arg[0]))
	{
		if (i == 1)
			printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n", cmd->arg[0]);
		return (255);
	}
	if (ft_isdigit(cmd->arg[0][0]))
	{
		n = ft_arrlen(cmd->arg);
		if (n > 1)
		{
			if (i == 1)
				printf("exit\n");
			write(2, "my minishell: exit: too many arguments\n", 40);
			g_f->exit_code = 1;
			return (-1);
		}
		if (n == 1)
			x = exit_function3(cmd, i, x);
	}
	return (x);
}

int	exit_function(t_parser *cmd, int i)
{
	long long	x;

	x = 0;
	if (!ft_strncmp(cmd->cmd, "exit", 4) && ft_strlen(cmd->cmd) == 4)
	{
		if (cmd->opt == NULL && cmd->arg == NULL)
		{
			if (i == 1)
				printf("exit\n");
			return (0);
		}
		if (cmd->opt)
		{
			if (i == 1)
				printf("exit\n");
			printf("bash: exit: %s: numeric argument required\n",
				cmd->opt);
			return (255);
		}
		if (cmd->arg)
			x = exit_function2(cmd, i, x);
		return (x);
	}
	return (-2);
}

int	exit_0(t_parser *tmp)
{
	int	m;

	m = exit_function(tmp, 1);
	if (m == -1)
	{
		g_f->p = 1;
		return (1);
	}
	exit(m);
	return (0);
}

char	*exit_sort(char *str)
{
	char	*tmp;

	if (g_f->exit_code > 255)
		g_f->exit_code /= 255;
	if (g_f->exit_code == 256)
		g_f->exit_code = 255;
	else if (g_f->exit_code == 2 && g_f->a != 3)
		g_f->p = 130;
	else if (g_f->exit_code == 3 && g_f->a != 3)
		g_f->p = 131;
	if (g_f->flg == -1)
		g_f->p = 1;
	if (g_f->a == 1)
		g_f->p = 1;
	if (g_f->a == 2)
		g_f->p = 2;
	if (g_f->a == 3)
		g_f->p = 3;
	tmp = ft_itoa(g_f->p);
	str = ft_strjoin_s(str, tmp);
	free(tmp);
	g_f->a = 0;
	return (str);
}
