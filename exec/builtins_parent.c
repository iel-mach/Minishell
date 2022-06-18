/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:37:16 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 07:03:18 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_cmd(t_parser *tmp)
{
	char	*home;

	home = get_home("HOME=", tmp->cmd);
	getcwd(g_f->oldpwd, sizeof(g_f->oldpwd));
	if (tmp->arg == NULL || (!ft_strncmp(tmp->arg[0], "#", 1) \
		&& ft_strlen(tmp->arg[0]) == 1) || (!ft_strncmp(tmp->arg[0], "~", 1) \
		&& ft_strlen(tmp->arg[0]) == 1))
	{
		getcwd(g_f->oldpwd, sizeof(g_f->oldpwd));
		if (chdir(home) == -1)
			free(home);
		getcwd(g_f->pwd, sizeof(g_f->pwd));
		g_f->old_env = edit_ev(g_f->old_env, g_f->pwd, g_f->oldpwd);
	}
	else if (chdir(tmp->arg[0]) == -1)
	{
		perror (tmp->arg[0]);
		g_f->a = 1;
	}
	getcwd(g_f->pwd, sizeof(g_f->pwd));
	g_f->old_env = edit_ev(g_f->old_env, g_f->pwd, g_f->oldpwd);
	free(home);
}

void	close_function(t_child *t)
{
	close(t->fd[1]);
	if (t->in != 0)
		close (t->in);
	t->in = t->fd[0];
	if (t->fd_der[1] != 1 && t->fd_der[1] != 0)
		close(t->fd_der[1]);
	if (t->fd_der[0] != 1 && t->fd_der[0] != 0)
		close(t->fd_der[0]);
	free(t->fd_der);
	if (t->splt != NULL)
		free(t->splt);
}

t_pipe	*error_cases3(t_pipe *s)
{
	skipspaces1(s);
	if (s->content[s->i] == '\0')
	{
		free(s->l);
		return (NULL);
	}
	if (s->content[s->i] == '|')
	{
		if (s->content[s->i + 1] == '|')
			error(3);
		else
			error(1);
		return (NULL);
	}
	return (s);
}
