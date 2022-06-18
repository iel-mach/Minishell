/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joincmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:48:30 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/18 07:04:00 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count(t_parser *cmd)
{
	int	count;

	count = 0;
	if (cmd->arg != NULL)
		count = ft_arrlen(cmd->arg);
	if (cmd->opt != NULL)
		count += 1;
	if (cmd->cmd != NULL)
		count += 1;
	return (count);
}

char	**ft_joincmd(t_parser *cmd)
{
	char	**splt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	splt = malloc (sizeof(char *) * (ft_count(cmd) + 1));
	if (cmd->cmd != NULL)
	{
		splt[i++] = ft_strdup(cmd->cmd);
		if (cmd->opt != NULL)
			splt[i++] = ft_strdup(cmd->opt);
		if (cmd->arg != NULL)
		{
			while (cmd->arg[j])
				splt[i++] = ft_strdup(cmd->arg[j++]);
		}
		splt[i] = NULL;
	}
	return (splt);
}

char	*get_home(char *str, char *s1)
{
	int	i;

	i = 0;
	while (g_f->old_env[i])
	{
		if (!ft_strncmp(g_f->old_env[i], str, 5))
			return (ft_substr(g_f->old_env[i], 5,
					ft_strlen(g_f->old_env[i]) - 5));
		i++;
	}
	printf("bash: %s: HOME not set\n", s1);
	return (NULL);
}

int	position_exit(t_parser *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (!ft_strncmp(tmp->cmd, "exit", 4))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
