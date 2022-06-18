/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:02:04 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 07:14:00 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_herdoc(t_parser *cmd, int fd)
{
	char	*get;

	get = readline("herdoc>");
	while (ft_strcmp(get, cmd->rdr->herdoc))
	{
		if (get)
		{
			ft_putstr_fd(get, fd);
			ft_putstr_fd("\n", fd);
		}
		free(get);
		get = readline("herdoc>");
	}
	free(get);
	free(cmd->rdr->herdoc);
	close (fd);
}

t_child	*ft_child3(t_child *t, t_parser *tmp)
{
	if (t->splt[0] != '\0' && !ft_builtins(tmp))
	{
		if (execve(t->splt[0], t->splt, g_f->old_env) == -1)
		{
			ft_putstr_fd("my minishell: ", 2);
			ft_putstr_fd(tmp->cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		exit (0);
	}
	return (t);
}

t_child	*ft_child2(t_child *t, t_parser *tmp)
{
	if (t->fd_der[0] != 0)
	{
		dup2 (t->fd_der[0], 0);
		close(t->fd_der[0]);
	}
	if (t->fd_der[1] != 0)
	{
		dup2(t->fd_der[1], 1);
		close(t->fd_der[1]);
	}
	else if (t->fd_der[0] == -1)
		exit(1);
	if (ft_builtins(tmp) == 1)
	{
		g_f->p = 0;
		exit(0);
	}
	return (t);
}

t_child	*ft_child1(t_child *t, t_parser *tmp)
{
	t->splt = access_path(tmp);
	if (t->fd_der != 0 && !t->splt[0])
	{
		close(t->fd_der[0]);
		close (t->fd_der[1]);
		exit (0);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close (t->fd[0]);
	if (tmp->next == NULL)
	{
		close (t->fd[1]);
		t->out = 1;
	}
	dup2 (t->in, 0);
	dup2(t->out, 1);
	return (t);
}

void	ft_child(t_child *t, t_parser *tmp)
{
	int	m;

	t->fd_der = malloc(sizeof(int) * 2);
	t->fd_der[1] = 0;
	t->fd_der[0] = 0;
	open_der(tmp, t->fd_der);
	pipe(t->fd);
	t->out = t->fd[1];
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	t->pid = fork();
	if (t->pid == 0)
	{
		t = ft_child1(t, tmp);
		m = exit_function(tmp, 0);
		if (m != -2)
		{
			if (m == -1)
				exit (1);
			exit(m);
		}
		t = ft_child2(t, tmp);
		t = ft_child3(t, tmp);
	}
	close_function(t);
}
