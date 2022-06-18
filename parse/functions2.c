/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:44:13 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 07:06:07 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_env(char *ev, t_p *s)
{
	while (s->string[s->i] != '"' && s->string[s->i] != '\''
		&& s->string[s->i] != '$')
	{
		if ((s->string[s->i] >= 'a' && s->string[s->i] <= 'z')
			|| (s->string[s->i] >= 'A' && s->string[s->i] <= 'Z')
			|| (s->string[s->i] >= '0' && s->string[s->i] <= '9')
			|| s->string[s->i] == '_')
			ev = ft_strjoin(ev, s->string[s->i++]);
		else
			break ;
	}
	ev = ft_strjoin(ev, '=');
	return (ev);
}

t_norme	*skip_quote(t_norme *t, char *s)
{
	if (s[t->i] == '"')
	{
		t->i++;
		while (s[t->i] != '"')
			t->i++;
		if (s[t->i] != '\0')
			t->i++;
	}
	if (s[t->i] == '\'')
	{
		t->i++;
		while (s[t->i] != '\'')
			t->i++;
		if (s[t->i] != '\0')
			t->i++;
	}
	return (t);
}

int	count_pipes(char *s)
{
	t_norme	*t;
	int		x;

	t = malloc(sizeof(t_norme));
	t->x = 1;
	t->i = 0;
	while (s[t->i])
	{
		if (s[t->i] == '\'' || s[t->i] == '"')
			t = skip_quote(t, s);
		if (s[t->i] == '|')
			t->x++;
		if (s[t->i] == '\0')
			break ;
		t->i++;
	}
	x = t->x;
	free (t);
	return (x);
}

char	*dollar_check(t_p *s, char *str, int x)
{
	if (s->string[++s->i] == '?')
	{
		str = exit_sort(str);
		s->i++;
	}
	else if (ft_isdigit(s->string[s->i]))
	{
		s->i++;
		str = ft_strjoin(str, '\0');
	}
	else if (s->string[s->i] == '$')
	{
		s->i++;
		str = ft_strjoin_s(str, "$$");
	}
	else if (ft_isalpha(s->string[s->i])
		|| s->string[s->i] == '_')
		str = get_env(s, str, x);
	else
		str = ft_strjoin(str, '$');
	return (str);
}

void	free_env(void)
{
	int	i;

	i = 0;
	while (g_f->old_env[i])
	{
		free(g_f->old_env[i]);
		i++;
	}
	free(g_f->old_env);
}
