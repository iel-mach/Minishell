/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:11:32 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 03:31:35 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arg_parse_helper(t_p *s, t_parser *tmp)
{
	if (s->string[s->i] == ' ')
		skipspaces(s);
	if (tmp->arg != NULL)
		tmp->i++;
	if (tmp->arg == NULL)
	{
		tmp->i = 0;
		tmp->arg = malloc(((count_arg(s) + 1) * sizeof(char *)));
	}
	tmp->arg[tmp->i] = malloc(2);
	tmp->arg[tmp->i][0] = '\0';
}

t_parser	*creation_parse_n(t_parser *tmp)
{
	tmp = malloc(sizeof(t_parser));
	tmp->rdr = NULL;
	tmp->arg = NULL;
	tmp->cmd = NULL;
	tmp->opt = NULL;
	return (tmp);
}

t_pipe	*error_cases2(t_pipe *s)
{
	if (s->content[s->i] == '|'
		&& s->content[s->i + 1] == ' ')
	{
		s->i++;
		skipspaces1(s);
		if (s->content[s->i] == '|')
		{
			if (s->content[s->i + 1] == '|')
				error(3);
			else
				error(1);
			free(s->l);
			return (NULL);
		}
	}
	return (s);
}

t_p	*erorr_r4(t_p *s, t_rdr *r)
{
	if (s->string[s->i] == '<' && s->string[s->i + 1] == '>')
	{
		error(11);
		free(r);
		return (NULL);
	}
	if (s->string[s->i] == '<' || s->string[s->i] == '>')
	{
		r_errors1(s);
		free(r);
		return (NULL);
	}
	return (s);
}

t_p	*erorr_r5(t_p *s, t_rdr *r)
{
	if (s->string[s->i] == '<' && s->string[s->i + 1] == '>')
	{
		error(11);
		free (r);
		return (NULL);
	}
	if (s->string[s->i] == '<' || s->string[s->i] == '>')
	{
		r_errors1(s);
		free (r);
		return (NULL);
	}
	return (s);
}
