/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongles_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 05:41:03 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 05:42:12 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_dongle	*dongle_new(int id)
{
	t_dongle	*node;

	node = malloc(sizeof(t_dongle));
	if (!node)
		return (NULL);
	memset(node, 0, sizeof(t_dongle));
	node->id = id;
	node->released_at = 0;
	node->next = NULL;
	return (node);
}

void	dongle_add_back(t_dongle **lst, t_dongle *node)
{
	t_dongle	*cur;

	if (!*lst)
	{
		*lst = node;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

t_dongle	*dongle_at(t_data *data, int index)
{
	t_dongle	*cur;
	int			i;

	cur = data->dongles;
	i = 0;
	while (cur && i < index)
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}
