/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:29:18 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:46:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	r_errors1(t_p *s)
{
	int	n;

	if (s->string[s->i] == '<')
	{
		n = count_r(s, '<');
		if (n == 1)
			error(5);
		if (n == 2)
			error(6);
		if (n >= 3)
			error(7);
	}
	if (s->string[s->i] == '>')
	{
		n = count_r(s, '>');
		if (n == 1)
			error(8);
		if (n >= 2)
			error(9);
	}	
}

t_p	*error_r2(t_p *s)
{
	if (s->string[s->i] == '<')
	{
		s->i++;
		if (s->string[s->i] == ' ')
			skipspaces(s);
		if (s->string[s->i] == '\0')
		{
			error(4);
			return (NULL);
		}
		else if (s->string[s->i] != '>' && s->string[s->i] != '<')
		{
			error(12);
			return (NULL);
		}
	}
	if (s->string[s->i] == ' ')
		skipspaces(s);
	s = error_r3(s);
	if (s == NULL)
		return (NULL);
	return (s);
}

t_p	*error_r3(t_p *s)
{
	if (s->string[s->i] == '\0')
	{
		if (s->next != NULL)
			error(1);
		else
			error(4);
		return (NULL);
	}
	return (s);
}

int	count_r(t_p *s, char c)
{
	int	x;
	int	i;

	x = s->i;
	i = 0;
	while (s->string[x])
	{
		if (s->string[x] != ' ' && s->string[x] != '>'
			&& s->string[x] != '<')
			break ;
		if (s->string[x] == c)
			i++;
		x++;
	}
	return (i);
}

t_p	*error_r1(t_p *s)
{
	if (s->string[s->i] == '\0')
	{
		if (s->next != NULL)
			error(1);
		else
			error(4);
		return (NULL);
	}
	if (s->string[s->i] == '<' && s->string[s->i + 1] == '>')
	{
		error(11);
		return (NULL);
	}
	if (s->string[s->i] == '<' || s->string[s->i] == '>')
	{
		r_errors1(s);
		return (NULL);
	}
	return (s);
}
