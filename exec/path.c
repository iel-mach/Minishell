/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:32:54 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/18 03:28:32 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**findpath(char **s)
{
	int		i;
	char	*sub;
	char	**splt;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		if (!ft_strncmp("PATH", s[i], 4))
		{
			sub = ft_substr(s[i], 5, ft_strlen(s[i]) - 5);
			splt = ft_split(sub, ':');
			free (sub);
			return (splt);
		}
		i++;
	}
	return (NULL);
}

char	**splt_return(char **splt, char **spltenv)
{
	int		i;
	char	*check;

	i = 0;
	while (spltenv[i])
	{
		spltenv[i] = ft_strjoin(spltenv[i], '/');
		check = ft_strjoin_s(spltenv[i], splt[0]);
		if (access(check, X_OK) == 0)
		{
			free(splt[0]);
			splt[0] = check;
			return (splt);
		}
		i++;
	}
	return (splt);
}

char	**access_path(t_parser *cmd)
{
	char	**splt;
	char	**spltenv;

	splt = ft_joincmd(cmd);
	if (!cmd->cmd)
	{
		splt[0] = NULL;
		return (splt);
	}
	spltenv = findpath(g_f->old_env);
	if (!spltenv)
		return (splt);
	splt = splt_return(splt, spltenv);
	return (splt);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**edit_ev(char	**str, char *pwd, char *oldpwd)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp("PWD", str[i], 3))
		{
			free(str[i]);
			buff = ft_strjoin_n("PWD=", pwd);
			str[i] = ft_strdup(buff);
			free(buff);
		}
		if (!ft_strncmp("OLDPWD", str[i], 6))
		{
			buff = ft_strjoin_n("OLDPWD=", oldpwd);
			free(str[i]);
			str[i] = ft_strdup(buff);
			free(buff);
		}
		i++;
	}
	return (str);
}
