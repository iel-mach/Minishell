/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:22:45 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 04:34:57 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_cmd1(t_parser *cmd)
{
	int	x;

	if (cmd->arg == NULL)
		printf("\n");
	else
	{		
		x = 0;
		while (cmd->arg[x])
		{
			printf("%s", cmd->arg[x]);
			if (cmd->arg[x + 1] != NULL)
				printf(" ");
			x++;
		}
		printf("\n");
	}
}

void	echo_cmd2(t_parser *cmd)
{
	int	x;

	if (cmd->arg != NULL)
	{
		x = 0;
		while (cmd->arg[x])
		{
			if (!check_opt(cmd->arg[x]))
				break ;
			x++;
		}
		while (cmd->arg[x])
		{
			printf("%s", cmd->arg[x]);
			if (cmd->arg[x + 1] != NULL)
				printf(" ");
			x++;
		}
	}
	if (cmd->arg == NULL)
		printf("");
}

void	echo_cmd3(t_parser *cmd)
{
	int	x;

	if (cmd->arg == NULL)
		printf("%s\n", cmd->opt);
	else
	{
		printf("%s ", cmd->opt);
		x = 0;
		while (cmd->arg[x])
		{
			printf("%s", cmd->arg[x]);
			if (cmd->arg[x + 1] != NULL)
				printf(" ");
			x++;
		}
		printf("\n");
	}
}

void	env_cmd(t_parser *cmd)
{
	int	x;
	int	n;

	if (cmd->opt == NULL && cmd->arg == NULL)
	{
		x = 0;
		while (g_f->old_env[x])
		{
			n = 0;
			while (g_f->old_env[x][n])
			{
				if (g_f->old_env[x][n] == '=')
				{
					printf("%s\n", g_f->old_env[x]);
					break ;
				}
				n++;
			}
			x++;
		}
	}
	else if (cmd->opt != NULL)
		printf("env: illegal option -- %c\n", cmd->opt[1]);
	else if (cmd->arg != NULL)
		printf("env: %s: No such file or directory\n", cmd->arg[0]);
}
