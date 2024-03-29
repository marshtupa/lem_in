/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:42:50 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/21 13:59:25 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clean_matrix(_Bool ***m)
{
	int		i;

	i = 0;
	if (!(m && *m))
		return ;
	while (i < g_lem_in->rooms)
		free((*m)[i++]);
	free(*m);
}

static void	free_nodes(t_rooms **nodes)
{
	t_rooms	*temp;

	if (!nodes)
		return ;
	while (*nodes)
	{
		temp = *nodes;
		*nodes = (*nodes)->next;
		if (temp->name)
			ft_strdel(&temp->name);
		free(temp);
	}
}

static void	free_data(t_lst **data)
{
	t_lst	*temp;

	if (!data)
		return ;
	while (*data)
	{
		temp = *data;
		*data = (*data)->next;
		if (temp->line)
			ft_strdel(&(temp->line));
		free(temp);
	}
}

int			project_free(char *message, char *line)
{
	if (line)
		ft_strdel(&line);
	if (g_np)
		clean_matrix(&g_np);
	if (g_mnp)
		clean_matrix(&g_mnp);
	if (g_lem_in)
	{
		free_data(&g_lem_in->data);
		free_nodes(&g_lem_in->nodes);
		clean_matrix(&g_lem_in->matrix);
		free_words(&g_lem_in->names);
		ft_strdel(&g_lem_in->status);
		free(g_lem_in);
	}
	if (message)
		print_error(message);
	exit(0);
}
