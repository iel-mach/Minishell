/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:24:46 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 23:56:14 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*check_quote(t_pipe *s, char c)
{
	int	b;
	int	q;

	b = 0;
	q = s->i;
	q++;
	while (s->content[q])
	{
		if (s->content[q] == c)
			return (s);
		q++;
	}
	free(s->l);
	error(0);
	return (NULL);
}

char	*double_quote(t_pipe *s)
{
	s = check_quote(s, '"');
	if (s == NULL)
		return (NULL);
	if (s->content[s->i] == '"')
		s->l = ft_strjoin(s->l, '"');
	s->i++;
	while (s->content[s->i] != '"')
	{
		if (s->content[s->i] == '\0')
		{
			error(0);
			free(s->l);
			return (NULL);
		}
		if (s->content[s->i] != '"')
			s->l = ft_strjoin(s->l, s->content[s->i++]);
		if (s->content[s->i] == '"')
			break ;
	}
	if (s->content[s->i] == '"')
		s->l = ft_strjoin(s->l, '"');
	if (s->content[s->i] != '\0')
		s->i++;
	return (s->l);
}

char	*single_quote(t_pipe *s)
{
	s = check_quote(s, '\'');
	if (s == NULL)
		return (NULL);
	if (s->content[s->i] == '\'')
		s->l = ft_strjoin(s->l, '\'');
	s->i++;
	while (s->content[s->i] != '\'')
	{
		if (s->content[s->i] == '\0')
		{
			error(0);
			free(s->l);
			return (NULL);
		}
		s->l = ft_strjoin(s->l, s->content[s->i++]);
	}
	if (s->content[s->i] == '\'')
		s->l = ft_strjoin(s->l, '\'');
	s->i++;
	return (s->l);
}

char	*getenv1(t_pipe *s)
{
	int	i;

	i = 0;
	while (g_f->old_env[i])
	{
		if (!ft_strncmp(s->p, g_f->old_env[i], ft_strlen(s->p)))
			return (g_f->old_env[i]);
		if (g_f->old_env[i] == NULL)
			break ;
		i++;
	}
	return (NULL);
}

char	*get_env(t_p *t, char *str, int x)
{
	t_pipe	*s;
	char	*m;

	s = malloc(sizeof(t_pipe));
	s->p = malloc(2);
	s->p[0] = '\0';
	s->p = check_env(s->p, t);
	s->ev = ft_strdup(getenv1(s));
	if (s->ev == NULL)
	{
		if (x == 0)
		{
			m = ft_substr(s->p, 0, ft_strlen(s->p) - 1);
			printf("my minishell: $%s: ambiguous redirect\n", m);
			free (m);
		}
		str = ft_strjoin(str, '\0');
	}
	else
		str = add_env(s->ev, str);
	free(s->p);
	if (s->ev != NULL)
		free (s->ev);
	free (s);
	return (str);
}
