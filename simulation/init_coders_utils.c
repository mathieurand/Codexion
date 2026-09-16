/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:36:52 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:41:09 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder	*coder_new(t_data *data, int id)
{
	t_coder	*node;

	node = malloc(sizeof(t_coder));
	if (!node)
		return (NULL);
	memset(node, 0, sizeof(t_coder));
	node->id = id;
	node->compiles_done = 0;
	node->data = data;
	node->next = NULL;
	return (node);
}

void	coder_add_back(t_coder **lst, t_coder *node)
{
	t_coder	*cur;

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