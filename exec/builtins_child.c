/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:57:02 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 03:25:59 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_builtins3(t_parser *cmd)
{
	if ((!ft_strncmp(cmd->cmd, "export", 6) && ft_strlen(cmd->cmd) == 6))
	{
		if (cmd->opt != NULL || cmd->arg != NULL)
			export1(cmd);
		else if (cmd->opt == NULL && cmd->arg == NULL)
			export3();
		return (1);
	}
	else if (!ft_strncmp(cmd->cmd, "unset", 4) && ft_strlen(cmd->cmd) == 5)
		return (1);
	return (0);
}

int	ft_builtins2(t_parser *cmd)
{
	if (((cmd_echo(cmd->cmd) && ft_strlen(cmd->cmd) == 4)))
	{
		if (cmd->opt == NULL && cmd->rdr == NULL)
			echo_cmd1(cmd);
		else if (cmd->rdr == NULL && cmd->opt != NULL)
		{
			if (check_opt(cmd->opt))
				echo_cmd2(cmd);
			else if (!check_opt(cmd->opt))
				echo_cmd3(cmd);
		}
		return (1);
	}
	else if (cmd_env(cmd->cmd) && ft_strlen(cmd->cmd) == 3)
	{
		env_cmd(cmd);
		return (1);
	}
	return (0);
}

int	ft_builtins1(t_parser *cmd)
{
	char	buff[256];

	if ((cmd_pwd(cmd->cmd) && ft_strlen(cmd->cmd) == 3))
	{
		if (cmd->opt == NULL)
		{
			if (getcwd(buff, sizeof(buff)) == NULL)
				printf("%s\n", g_f->pwd);
			else
				printf ("%s\n", buff);
		}
		else
			printf("my minishell : pwd: %s: invalid option\n", cmd->opt);
		return (1);
	}
	else if (!ft_strncmp(cmd->cmd, "cd", 2) && ft_strlen(cmd->cmd) == 2)
		return (1);
	return (0);
}

int	ft_builtins(t_parser *cmd)
{
	int	x;

	x = 0;
	if ((cmd_pwd(cmd->cmd) && ft_strlen(cmd->cmd) == 3)
		|| (!ft_strncmp(cmd->cmd, "cd", 2) && ft_strlen(cmd->cmd) == 2))
	{
		x = ft_builtins1(cmd);
		return (x);
	}
	else if ((cmd_echo(cmd->cmd) && ft_strlen(cmd->cmd) == 4)
		|| (cmd_env(cmd->cmd) && ft_strlen(cmd->cmd) == 3))
	{
		x = ft_builtins2(cmd);
		return (x);
	}
	else if ((!ft_strncmp(cmd->cmd, "export", 6) && ft_strlen(cmd->cmd) == 6)
		|| (!ft_strncmp(cmd->cmd, "unset", 4) && ft_strlen(cmd->cmd) == 5))
	{
		x = ft_builtins3(cmd);
		return (x);
	}
	return (0);
}
