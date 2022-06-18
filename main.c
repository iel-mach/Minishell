/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:29:05 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 05:44:44 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tp(t_p *tmp, t_parser *tmp1)
{
	int			i;

	while (tmp)
	{
		free(tmp->string);
		tmp = tmp->next;
	}
	while (tmp1)
	{
		if (tmp1->arg != NULL)
		{
			i = 0;
			while (tmp1->arg[i])
				free(tmp1->arg[i++]);
			free(tmp1->arg);
		}
		if (tmp1->cmd != NULL)
			free(tmp1->cmd);
		if (tmp1->opt != NULL)
			free (tmp1->opt);
		tmp1 = tmp1->next;
	}
}

void	free_functions(t_p *ps, t_parser *parse, t_pipe *s)
{
	t_p			*tmp;
	t_parser	*tmp1;

	tmp = ps;
	tmp1 = parse;
	free_tp(tmp, tmp1);
	while (ps)
	{
		tmp = ps;
		ps = ps->next;
		free(tmp);
	}
	while (parse)
	{
		tmp1 = parse;
		parse = parse->next;
		free(tmp1);
	}
	free (s->content);
	free(s);
}

void	handler(int i)
{
	(void)i;
	if (g_f->flg == 1)
	{
		printf("\n");
		g_f->flg = -1;
		close(0);
	}
	else
	{
		rl_replace_line("", 0);
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_f->p = 1;
	return ;
}

void	init_minishell(t_pipe *s, t_parser *parse, t_p *ps)
{
	if (s->content == NULL)
	{
		printf("exit\n");
		exit(g_f->exit_code);
	}
	if (s->content[0])
	{
		add_history(s->content);
		ps = ft_split_pipe_line(s);
		if (ps == NULL)
			g_f->p = 258;
		if (ps != NULL)
		{
			parse = ft_lexer(ps);
			if (parse != NULL)
				ft_mycmd(parse);
		}
		free_functions(ps, parse, s);
	}
}

int	main(int ac, char **av, char **env)
{
	t_parser	*parse;
	t_p			*ps;
	t_pipe		*s;

	(void)av;
	g_f = malloc(sizeof(t_ex));
	g_f->old_env = add_ev(env);
	g_f->exit_code = 0;
	g_f->p = 0;
	g_f->flg = 0;
	if (ac == 1)
	{
		while (1)
		{
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, handler);
			parse = NULL;
			ps = NULL;
			s = malloc(sizeof(t_pipe));
			g_f->fdex = dup(0);
			s->content = readline("my minishell $: ");
			init_minishell(s, parse, ps);
		}
	}
}
