/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:09:31 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 04:25:00 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cmd_parse(t_p *s, t_parser *t)
{
	t->cmd = malloc(2);
	t->cmd[0] = '\0';
	while (s->string[s->i] != ' ' && s->string[s->i])
	{
		if (s->string[s->i] == '"')
			t->cmd = quote_value(s, t->cmd, 1);
		if (s->string[s->i] == '\'')
			t->cmd = quote_value(s, t->cmd, 1);
		if (s->string[s->i] == '$')
			t->cmd = dollar_check(s, t->cmd, 1);
		if (s->string[s->i] == '>' || s->string[s->i] == '<')
			break ;
		if (s->string[s->i] != '"' && s->string[s->i] != '\''
			&& s->string[s->i] != '>' && s->string[s->i] != '<'
			&& s->string[s->i] != '\0' && s->string[s->i] != ' ')
			t->cmd = ft_strjoin(t->cmd, s->string[s->i++]);
	}
	return (t->cmd);
}

char	*arg_parse(t_p *s, t_parser *tmp)
{
	arg_parse_helper(s, tmp);
	while (s->string[s->i])
	{
		if (s->string[s->i] == ' ' || s->string[s->i] == '>'
			|| s->string[s->i] == '<')
			break ;
		if (s->string[s->i] == '"')
			tmp->arg[tmp->i] = quote_value(s, tmp->arg[tmp->i], 1);
		if (s->string[s->i] == '\'')
			tmp->arg[tmp->i] = quote_value(s, tmp->arg[tmp->i], 1);
		if (s->string[s->i] == '$')
			tmp->arg[tmp->i] = dollar_check(s, tmp->arg[tmp->i], 1);
		if (s->string[s->i] != ' ' && s->string[s->i] != '\''
			&& s->string[s->i] != '"' && s->string[s->i] != '\0'
			&& s->string[s->i] != '$')
			tmp->arg[tmp->i] = ft_strjoin(tmp->arg[tmp->i], s->string[s->i++]);
	}
	return (tmp->arg[tmp->i]);
}

char	*opt_parse(t_p *s, t_parser *tmp)
{
	tmp->opt = malloc(2);
	tmp->opt[0] = '\0';
	while (s->string[s->i] != ' ' && s->string[s->i])
	{
		if (s->string[s->i] == '\'')
			tmp->opt = quote_value(s, tmp->opt, 1);
		if (s->string[s->i] == '"')
			tmp->opt = quote_value(s, tmp->opt, 1);
		if (s->string[s->i] != '\'' && s->string[s->i] != '"'
			&& s->string[s->i] != ' ' && s->string[s->i] != '\0')
			tmp->opt = ft_strjoin(tmp->opt, s->string[s->i++]);
	}
	return (tmp->opt);
}

t_parser	*creation_parse(t_parser *tmp, t_p *s)
{
	t_rdr	*tmp1;

	tmp = creation_parse_n(tmp);
	while (s->string[s->i])
	{
		if ((s->string[s->i] == '>' || s->string[s->i] == '<')
			&& (s->string[s->i] != '"' || s->string[s->i] != '\''))
		{
			tmp1 = rdr_creation(s, tmp);
			if (tmp1 == NULL)
			{
				g_f->p = 258;
				free(tmp);
				return (NULL);
			}
			add_back_rdr(tmp1, &tmp->rdr);
		}
		tmp = creation_parser_n(tmp, s);
		if (s->string[s->i] == '\0')
			break ;
	}
	if (tmp->arg != NULL)
		tmp->arg[++tmp->i] = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_parser	*ft_lexer(t_p *s)
{
	t_parser	*t;
	t_parser	*tmp;

	t = NULL;
	while (s)
	{
		s->i = 0;
		tmp = creation_parse(tmp, s);
		if (tmp == NULL)
			return (NULL);
		add_back(tmp, &t);
		s = s->next;
	}
	free(s);
	return (t);
}
