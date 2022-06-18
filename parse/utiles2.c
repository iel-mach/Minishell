/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:26:27 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:46:43 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			break ;
		i++;
	}
	if (s[i] == '\0')
		return (0);
	return (1);
}

void	skipspaces1(t_pipe *s)
{
	while (s->content[s->i] == ' ')
		s->i++;
}

char	*add_env(char *ev, char *str)
{
	int	i;

	i = 0;
	while (ev[i])
	{
		if (ev[i] == '=')
		{
			i++;
			while (ev[i])
				str = ft_strjoin(str, ev[i++]);
		}
		if (ev[i] != '\0')
			i++;
	}
	return (str);
}

void	error(int i)
{
	if (i == 0)
		write(1, "Syntax Error\n", 13);
	if (i == 1)
		write(1, "syntax error near unexpected token `|'\n", 39);
	if (i == 3)
		write(1, "syntax error near unexpected token `||'\n", 40);
	if (i == 4)
		write (1, "syntax error near unexpected token `newline'\n", 45);
	if (i == 5)
		write(1, "syntax error near unexpected token `<'\n", 39);
	if (i == 6)
		write(1, "syntax error near unexpected token `<<'\n", 40);
	if (i == 7)
		write(1, "syntax error near unexpected token `<<<'\n", 41);
	if (i == 8)
		write(1, "syntax error near unexpected token `>'\n", 39);
	if (i == 9)
		write(1, "syntax error near unexpected token `>>'\n", 40);
	if (i == 10)
		write(1, "syntax error near unexpected token `>>>'\n", 41);
	if (i == 11)
		write (1, "syntax error near unexpected token `<>'\n", 40);
	if (i == 12)
		write(2, "we didn't handle this case\n", 27);
}

void	skipspaces(t_p *s)
{
	while (s->string[s->i])
	{
		if (s->string[s->i] != ' ')
			break ;
		s->i++;
	}
}
