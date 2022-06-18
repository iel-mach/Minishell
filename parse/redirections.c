/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:16:32 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 03:37:52 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_rdr	*redirections(t_rdr *r, t_p *s, t_parser *t)
{
	if (s->string[s->i] == '>')
	{
		s->i++;
		if (s->string[s->i] == '>')
			r = input_dr(s, r, t);
		else
			r = input_sr(s, r, t);
	}
	else if (s->string[s->i] == '<')
	{
		s->i++;
		if (s->string[s->i] == '<')
			r = herdoc(s, r, t);
		else
			r = output_sr(s, r, t);
	}
	if (r == NULL)
		return (NULL);
	return (r);
}

t_rdr	*output_sr(t_p *s, t_rdr *r, t_parser *t)
{
	s = error_r2(s);
	if (s == NULL)
		return (NULL);
	s = erorr_r4(s, r);
	if (s == NULL)
		return (NULL);
	if (s->string[s->i] != '.' && s->string[s->i] != '#'
		&& s->string[s->i] != '&' && s->string[s->i] != '*')
	{
		t = stock_value(s, r, 2, t);
		if (t == NULL)
			return (NULL);
	}
	else
	{
		error(0);
		free(r);
		return (NULL);
	}
	return (r);
}

t_rdr	*herdoc(t_p *s, t_rdr *r, t_parser *t)
{
	s->i++;
	s = error_r2(s);
	if (s == NULL)
	{
		free (r);
		return (NULL);
	}
	s = erorr_r5(s, r);
	if (s == NULL)
		return (NULL);
	if (s->string[s->i] != '.' && s->string[s->i] != '#'
		&& s->string[s->i] != '&' && s->string[s->i] != '*')
		stock_value(s, r, 3, t);
	else
	{
		error(0);
		free(r);
		return (NULL);
	}
	return (r);
}

t_rdr	*input_sr(t_p *s, t_rdr *r, t_parser *t)
{
	if (s->string[s->i] == ' ')
		skipspaces(s);
	s = error_r1(s);
	if (s == NULL)
	{
		free (r);
		return (NULL);
	}
	if (s->string[s->i] != '.' && s->string[s->i] != '#'
		&& s->string[s->i] != '&' && s->string[s->i] != '*')
	{
		t = stock_value(s, r, 0, t);
		if (t == NULL)
			return (NULL);
	}
	else
	{
		error(0);
		free(r);
		return (NULL);
	}
	return (r);
}

t_rdr	*input_dr(t_p *s, t_rdr *r, t_parser *t)
{
	s->i++;
	if (s->string[s->i] == ' ')
		skipspaces(s);
	s = error_r1(s);
	if (s == NULL)
	{
		free(r);
		return (NULL);
	}
	if (s->string[s->i] != '.' && s->string[s->i] != '#'
		&& s->string[s->i] != '&' && s->string[s->i] != '*')
	{
		t = stock_value(s, r, 1, t);
		if (t == NULL)
			return (NULL);
	}
	else
	{
		error(0);
		free (r);
		return (NULL);
	}
	return (r);
}
