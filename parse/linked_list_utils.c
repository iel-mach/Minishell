/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:23:37 by hboukili          #+#    #+#             */
/*   Updated: 2022/06/16 02:46:08 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_back(t_parser *tmp, t_parser **node)
{
	t_parser	*last_node;

	if (*node == NULL)
		*node = tmp;
	else
	{
		last_node = (*node);
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = tmp;
	}
}

void	add_back_rdr(t_rdr *tmp, t_rdr **node)
{
	t_rdr	*last_node;

	if (*node == NULL)
		*node = tmp;
	else
	{
		last_node = (*node);
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = tmp;
	}
}

void	add_last(t_p *tmp, t_p **node)
{
	t_p	*last_node;

	if (*node == NULL)
		*node = tmp;
	else
	{
		last_node = (*node);
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = tmp;
	}
}

t_p	*ps_creation(char *l)
{
	t_p	*t;

	t = malloc(sizeof(t_p));
	t->string = ft_strdup(l);
	free (l);
	t->next = NULL;
	return (t);
}

t_rdr	*rdr_creation(t_p *s, t_parser *t)
{
	t_rdr	*r;

	r = malloc(sizeof(t_rdr));
	while (s->string[s->i])
	{
		r = redirections(r, s, t);
		if (r == NULL)
			return (NULL);
		if (s->string[s->i] == ' ' || s->string[s->i] == '>'
			|| s->string[s->i] == '<')
			break ;
	}
	r->next = NULL;
	return (r);
}
