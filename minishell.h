/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:41:57 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 07:03:30 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft_m/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct env_exit
{
	char	**old_env;
	int		exit_code;
	int		p;
	int		fdex;
	int		flg;
	int		a;
	char	oldpwd[255];
	char	pwd[255];
}	t_ex;
t_ex	*g_f;

typedef struct split_pipe
{
	char	*content;
	int		i;
	int		x;
	int		pipe;
	int		n;
	char	**env;
	char	*ev;
	char	*p;
	char	*l;
}	t_pipe;

typedef struct child
{
	int			fd[2];
	int			in;
	int			out;
	int			pid;
	int			*fd_der;
	char		**splt;
}	t_child;

typedef struct rdr
{
	char		*rdr_value;
	struct rdr	*next;
	char		*herdoc;
	int			fd;
	int			type;
}	t_rdr;

typedef struct pipe_line
{
	char				*string;
	int					i;
	struct pipe_line	*next;
}	t_p;

typedef struct norme
{
	int	i;
	int	x;
	int	b;
	int	o;
	int	n;
	int	c;
}	t_norme;

typedef struct parser
{
	char			*cmd;
	char			*opt;
	char			**arg;
	int				i;
	t_rdr			*rdr;
	struct parser	*next;
	char			**env;
}	t_parser;

int			ft_check_digit(char *str);
int			position_exit(t_parser *tmp);
t_parser	*ft_lexer(t_p *s);
void		error(int i);
int			check_spaces(char *s);
void		skipspaces(t_p *s);
t_rdr		*output_sr(t_p *s, t_rdr *r, t_parser *t);
t_rdr		*herdoc(t_p *s, t_rdr *r, t_parser *t);
t_rdr		*input_sr(t_p *s, t_rdr *r, t_parser *t);
t_rdr		*input_dr(t_p *s, t_rdr *r, t_parser *t);
int			check_o(char c);
int			count_cmd(char *s);
int			count_arg(t_p *t);
int			count_rdr(t_p *s);
t_parser	*stock_value(t_p *s, t_rdr *r, int b, t_parser *t);
void		add_back(t_parser *tmp, t_parser **node);
void		add_back_rdr(t_rdr *tmp, t_rdr **node);
void		add_last(t_p *tmp, t_p **node);
t_p			*ps_creation(char *l);
char		*double_quote(t_pipe *s);
char		*get_env(t_p *t, char *str, int x);
char		*single_quote(t_pipe *s);
char		*check_env(char *ev, t_p *s);
int			count_char(char *s, int i);
char		*add_env(char *ev, char *str);
t_pipe		*cases_1(t_pipe *s);
void		skipspaces1(t_pipe *s);
t_pipe		*cases_2(t_pipe *s);
t_p			*ft_split_pipe_line(t_pipe *s);
t_pipe		*content(t_pipe *s);
int			count_in_pipe(char *s, int i, t_pipe *t);
int			count_pipes(char *s);
int			ft_mycmd(t_parser *cmd);
int			ft_arrlen(char **env);
char		*ft_strjoin_s(char *s1, char *s2);
char		**add_ev( char **env);
char		*dollar_check(t_p *s, char *str, int x);
void		r_errors1(t_p *s);
t_p			*error_r2(t_p *s);
t_p			*error_r3(t_p *s);
int			count_r(t_p *s, char c);
t_p			*error_r1(t_p *s);
t_rdr		*rdr_creation(t_p *s, t_parser *tmp);
int			quotes_c(t_p *s, t_norme *l);
int			count_arg(t_p *s);
char		*quote_value(t_p *s, char *str, int x);
t_parser	*creation_parser_n(t_parser *tmp, t_p *s);
char		*cmd_parse(t_p *s, t_parser *t);
char		*arg_parse(t_p *s, t_parser *tmp);
char		*opt_parse(t_p *s, t_parser *tmp);
t_parser	*creation_parse(t_parser *tmp, t_p *s);
t_rdr		*redirections(t_rdr *r, t_p *s, t_parser *t);
char		*check_env(char *ev, t_p *s);
int			count_pipes(char *s);
int			check_opt(char *s);
int			check_export2(char *str);
int			check_export3(char *str);
int			check_unset2(char **str);
int			check_unset(char **str, char *s);
int			count_tusawi(char *str);
int			cmd_env(char *str);
int			cmd_echo(char *str);
int			cmd_pwd(char *str);
int			check_export(char *str, char **old_env, int n);
void		env_cmd(t_parser *cmd);
void		echo_cmd3(t_parser *cmd);
void		echo_cmd2(t_parser *cmd);
void		echo_cmd1(t_parser *cmd);
void		export1(t_parser *cmd);
void		export2(t_parser *cmd, t_norme *t);
void		free_env(void);
void		export3(void);
void		export4(t_norme *l);
void		unset1(t_parser *cmd);
void		unset2(t_parser *cmd, t_norme *l);
char		*ft_strjoin_n(char *s1, char *s2);
char		**ft_joincmd(t_parser *cmd);
char		*get_home(char *str, char *s1);
int			exit_function(t_parser *cmd, int i);
void		handler(int i);
void		arg_parse_helper(t_p *s, t_parser *tmp);
t_parser	*creation_parse_n(t_parser *tmp);
t_pipe		*error_cases2(t_pipe *s);
t_p			*erorr_r4(t_p *s, t_rdr *r);
t_p			*erorr_r5(t_p *s, t_rdr *r);
void		creat_files(int b, t_rdr *r);
int			ft_builtins(t_parser *cmd);
char		**findpath(char **s);
char		**access_path(t_parser *cmd);
int			ft_strcmp(char *s1, char *s2);
void		ft_child(t_child *t, t_parser *tmp);
void		open_der(t_parser *cmd, int *fd);
void		ft_herdoc(t_parser *cmd, int fd);
char		**edit_ev(char	**str, char *pwd, char *oldpwd);
void		cd_cmd(t_parser *tmp);
int			exit_0(t_parser *tmp);
void		close_function(t_child *t);
char		*exit_sort(char *str);
t_pipe		*error_cases3(t_pipe *s);

#endif