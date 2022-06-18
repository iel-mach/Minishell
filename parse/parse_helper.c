/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:37:02 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 23:50:39 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quotes_c(t_p *s, t_norme *l)
{
	if (s->string[l->i] == '"')
	{
		l->i++;
		while (s->string[l->i] != '"')
		{
			l->x++;
			l->i++;
		}
		l->i++;
	}
	if (s->string[l->i] == '\'')
	{
		l->i++;
		while (s->string[l->i] != '\'')
		{
			l->x++;
			l->i++;
		}
		l->i++;
	}
	return (l->x);
}

int	count_arg(t_p *s)
{
	t_norme	*l;
	int		x;

	l = malloc(sizeof(t_norme));
	l->i = s->i;
	l->x = 0;
	while (s->string[l->i])
	{
		l->x = quotes_c(s, l);
		if (s->string[l->i] == ' ')
			l->i++;
		if (s->string[l->i] != '"' && s->string[l->i] != '\''
			&& s->string[l->i] != '\0' && s->string[l->i] != ' ')
		{
			l->x++;
			l->i++;
		}
	}
	if (l->x == 0)
		l->x = 1;
	x = l->x;
	free(l);
	return (x);
}

char	*quote_value(t_p *s, char *str, int x)
{
	if (s->string[s->i] == '\'')
	{
		s->i++;
		while (s->string[s->i] != '\'')
			str = ft_strjoin(str, s->string[s->i++]);
		s->i++;
	}
	if (s->string[s->i] == '"')
	{
		s->i++;
		while (s->string[s->i] != '"')
		{
			if (s->string[s->i] == '$')
				str = dollar_check(s, str, x);
			else
				str = ft_strjoin(str, s->string[s->i++]);
			if (s->string[s->i] == '"')
				break ;
		}
		s->i++;
	}
	return (str);
}

t_parser	*creation_parser_n(t_parser *tmp, t_p *s)
{
	if (s->string[s->i] == ' ')
		skipspaces(s);
	if (s->string[s->i] != '>' && s->string[s->i] != '<'
		&& s->string[s->i] != '\0' && tmp->cmd == NULL
		&& s->string[s->i] != ' ')
		tmp->cmd = cmd_parse(s, tmp);
	if (s->string[s->i] == ' ')
		skipspaces(s);
	if (((s->string[s->i] == '-') || ((s->string[s->i] == '"'
					|| s->string[s->i] == '\'') && s->string[s->i + 1] == '-'))
		&& tmp->opt == NULL && tmp->arg == NULL)
		tmp->opt = opt_parse(s, tmp);
	if (s->string[s->i] != '>' && s->string[s->i] != '<'
		&& s->string[s->i] != '\0' && s->string[s->i] != ' ')
		tmp->arg[tmp->i] = arg_parse(s, tmp);
	if (s->string[s->i] == ' ')
		skipspaces(s);
	return (tmp);
}
