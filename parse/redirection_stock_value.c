/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_stock_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:33:10 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/17 23:52:44 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_rdr	*herdoc_stock2(t_p *s, t_rdr *r)
{
	if (s->string[s->i] == '\'')
	{
		s->i++;
		while (s->string[s->i] != '\'')
			r->herdoc = ft_strjoin(r->herdoc, s->string[s->i++]);
		s->i++;
	}
	if (s->string[s->i] != '"' && s->string[s->i] != '\''
		&& s->string[s->i] != '\0' && s->string[s->i] != ' ')
		r->herdoc = ft_strjoin(r->herdoc, s->string[s->i++]);
	return (r);
}

t_rdr	*herdoc_stock(t_p *s, t_rdr *r)
{
	r->herdoc = malloc(1);
	r->herdoc[0] = '\0';
	while (s->string[s->i])
	{
		if (s->string[s->i] == '>' || s->string[s->i] == '<'
			|| s->string[s->i] == ' ')
			break ;
		if (s->string[s->i] == '"')
		{
			s->i++;
			while (s->string[s->i] != '"')
				r->herdoc = ft_strjoin(r->herdoc, s->string[s->i++]);
			s->i++;
		}
		r = herdoc_stock2(s, r);
	}
	return (r);
}

t_rdr	*stock_value2(t_p *s, t_rdr *r, int b, t_parser *t)
{
	(void)t;
	if (s->string[s->i] == '\'')
			r->rdr_value = quote_value(s, r->rdr_value, 0);
	if (s->string[s->i] == '"' && b != 3)
	{
		r->rdr_value = quote_value(s, r->rdr_value, 0);
		if (r->rdr_value == NULL)
			return (NULL);
	}
	if ((s->string[s->i] != '>' && s->string[s->i] != '<'
			&& s->string[s->i] != '"' && s->string[s->i] != '\''
			&& s->string[s->i] != '\0') || (s->string[s->i] != '$'))
		r->rdr_value = ft_strjoin(r->rdr_value, s->string[s->i++]);
	return (r);
}

t_parser	*stock_value(t_p *s, t_rdr *r, int b, t_parser *t)
{
	r->rdr_value = malloc(2);
	r->rdr_value[0] = '\0';
	if (b != 3)
	{
		while (s->string[s->i] != ' ' && s->string[s->i])
		{
			if (s->string[s->i] == '>' || s->string[s->i] == '<')
				break ;
			if (s->string[s->i] == '$' && b != 3)
			{
				r->rdr_value = dollar_check(s, r->rdr_value, 0);
				if (r->rdr_value == NULL)
					return (NULL);
			}
			r = stock_value2(s, r, b, t);
		}
	}
	if (b == 3)
		r = herdoc_stock(s, r);
	creat_files(b, r);
	return (t);
}
