/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:27:25 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 05:30:44 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export1(t_parser *cmd)
{
	t_norme	*t;
	int		n;

	t = malloc(sizeof(t_norme));
	if (cmd->opt != NULL)
	{
		printf("my minishell: export:`%s': not a valid identifier\n",
			cmd->opt);
		g_f->a = 1;
		return ;
	}
	if (cmd->arg == NULL)
		return ;
	n = ft_arrlen(g_f->old_env) + ft_arrlen(cmd->arg);
	cmd->env = malloc((((n + 1) * sizeof(char *))));
	t->i = 0;
	while (t->i < ft_arrlen(g_f->old_env))
		cmd->env[t->i++] = ft_strdup(g_f->old_env[t->i]);
	t->o = 0;
	t->x = 0;
	export2(cmd, t);
	free_env();
	free(t);
	g_f->old_env = cmd->env;
}

void	export2(t_parser *cmd, t_norme *t)
{
	while (cmd->arg[t->o])
	{
		t->b = check_export(cmd->arg[t->o], cmd->env, t->i);
		if (t->b == -1)
		{
			if (!check_export2(cmd->arg[t->o]) || (cmd->arg[t->o][0] == '\0'))
			{
				printf("my minishell: export:`%s': not a valid identifier\n",
					cmd->arg[t->o]);
				g_f->a = 1;
			}
			else
				cmd->env[t->i++] = ft_strdup(cmd->arg[t->o]);
		}
		else if (t->b != -1 && t->b != -2)
		{
			t->x = 0;
			cmd->env[t->b][0] = '\0';
			while (cmd->arg[t->o][t->x])
				cmd->env[t->b] = ft_strjoin(cmd->env[t->b],
						cmd->arg[t->o][t->x++]);
		}
		t->o++;
	}
	cmd->env[t->i] = NULL;
}

void	export3(void)
{
	t_norme	*l;

	l = malloc(sizeof(t_norme));
	l->i = 0;
	while (g_f->old_env[l->i])
	{
		printf("declare -x ");
		l->x = 0;
		l->c = 0;
		while (g_f->old_env[l->i] && g_f->old_env[l->i][l->x])
		{
			if (l->x != 0 && g_f->old_env[l->i][l->x - 1] == '=' && l->c == 0)
			{
				printf("\"");
				l->c++;
			}
			printf("%c", g_f->old_env[l->i][l->x]);
			l->x++;
		}
		export4(l);
	}
	free(l);
}

void	export4(t_norme *l)
{
	l->n = 0;
	if (count_tusawi(g_f->old_env[l->i]) != 0 && l->n == 0)
	{
		printf("\"");
		l->n++;
	}
	printf("\n");
	l->i++;
}
