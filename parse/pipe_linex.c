/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_linex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:51:10 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 05:58:56 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*error_cases(t_pipe *s)
{
	if (s->i == 0 && s->content[s->i] == '|')
	{
		if (s->content[s->i + 1] == '|')
			error(3);
		else
			error(1);
		free(s->l);
		return (NULL);
	}
	if (s->content[s->i] == ' ' && s->i == 0)
		s = error_cases3(s);
	if (s != NULL)
		s = error_cases2(s);
	if (s == NULL)
		return (NULL);
	return (s);
}

t_pipe	*cases_1(t_pipe *s)
{
	if (s->content[s->i] == ' ' && s->content[s->i - 1] == '|')
		s->i++;
	if ((s->content[s->i] == '$' && s->content[s->i + 1] == '\''))
		s->i++;
	if (s->content[s->i] == '"')
	{
		s->l = double_quote(s);
		if (s->l == NULL)
			return (NULL);
	}
	if (s->content[s->i] == '$' && s->content[s->i + 1] == '"')
		s->i++;
	return (s);
}

t_pipe	*cases_2(t_pipe *s)
{
	if (s->content[s->i] == '\'')
	{
		s->l = single_quote(s);
		if (s->l == NULL)
			return (NULL);
	}
	if (s->content[s->i] != '"' && s->content[s->i] != '\''
		&& s->content[s->i] != '\0')
		s->l = ft_strjoin(s->l, s->content[s->i++]);
	if (s->content[s->i] == '|' && (s->content[s->i + 1] == '\0'))
	{
		error(0);
		free(s->l);
		return (NULL);
	}
	if (s->content[s->i] == '|' && s->content[s->i + 1] == '|')
	{
		error(3);
		free(s->l);
		return (NULL);
	}
	return (s);
}

t_pipe	*content(t_pipe *s)
{
	s->l = malloc(2);
	s->l[0] = '\0';
	s = error_cases(s);
	if (s == NULL)
		return (NULL);
	if (s->content[s->i] == '|')
		s->i++;
	while (s->content[s->i] != '\0')
	{
		s = cases_1(s);
		if (s == NULL)
			return (NULL);
		if (s->content[s->i] == '|')
			break ;
		s = cases_2(s);
		if (s == NULL)
			return (NULL);
	}
	return (s);
}

t_p	*ft_split_pipe_line(t_pipe *s)
{
	t_p	*tmp;
	t_p	*ps;

	ps = NULL;
	s->p = NULL;
	s->ev = NULL;
	s->pipe = 0;
	s->n = count_pipes(s->content);
	s->i = 0;
	while (s->pipe < s->n)
	{
		s = content(s);
		if (s == NULL)
			return (NULL);
		tmp = ps_creation(s->l);
		add_last(tmp, &ps);
		s->pipe++;
	}
	return (ps);
}
