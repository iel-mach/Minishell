/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:53:29 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:54:22 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset1(t_parser *cmd)
{
	t_norme	*l;

	l = malloc(sizeof(t_norme));
	if (cmd->opt != NULL)
	{
		printf("mymishell: unset: %c%c: invalid option\n",
			cmd->opt[0], cmd->opt[1]);
		return ;
	}
	if (!cmd->arg)
		return ;
	l->n = ft_arrlen(g_f->old_env) - check_unset2(cmd->arg);
	cmd->env = malloc((l->n + 1) * sizeof(char *));
	l->i = 0;
	l->n = 0;
	unset2(cmd, l);
	cmd->env[l->n] = NULL;
	free_env();
	free (l);
	g_f->old_env = cmd->env;
}

void	unset2(t_parser *cmd, t_norme *l)
{
	while (cmd->arg[l->i])
	{
		if (ft_isdigit(cmd->arg[l->i][0]))
			printf("bash: unset: `%s': not a valid identifier\n",
				cmd->arg[l->i]);
		else if (!check_export2(cmd->arg[l->i]))
			printf("bash: unset: `%s': not a valid identifier\n",
				cmd->arg[l->i]);
		l->i++;
	}
	l->i = 0;
	while (g_f->old_env[l->i])
	{
		l->x = check_unset(cmd->arg, g_f->old_env[l->i]);
		if (l->x == -1)
			l->i++;
		if (l->x != -1)
			cmd->env[l->n++] = ft_strdup(g_f->old_env[l->i++]);
	}
}
