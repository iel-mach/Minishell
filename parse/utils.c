/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:20:20 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 03:04:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	creat_files(int b, t_rdr *r)
{
	if (b == 0)
	{
		r->type = 0;
		r->fd = open(r->rdr_value, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	}
	if (b == 1)
	{
		r->type = 1;
		r->fd = open(r->rdr_value, O_CREAT | O_RDWR | O_APPEND, 0777);
	}
	if (b == 2)
	{
		r->type = 2;
		r->fd = open(r->rdr_value, O_RDWR, 0777);
	}
	if (b == 3)
	{
		r->type = 3;
		r->fd = open("/tmp/herdoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
}

int	count_rdr(t_p *s)
{
	int	i;

	i = s->i;
	while (s->string[i] && s->string[i] != ' ')
	{
		if (s->string[i] == '<' || s->string[i] == '>')
			break ;
		i++;
	}
	return (i);
}

int	ft_arrlen(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	if (i == 0)
		return (1);
	return (i);
}

char	**add_ev( char **env)
{
	int		i;
	char	**ev;
	int		l;

	i = 0;
	l = 0;
	ev = malloc ((ft_arrlen(env) + 1) * (sizeof(char *)));
	while (i < ft_arrlen(env))
	{
		ev[l] = ft_strdup(env[i]);
		l++;
		i++;
	}
	ev[l] = NULL;
	return (ev);
}
