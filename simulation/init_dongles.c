/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 05:37:33 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 05:39:50 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


static int	init_one(t_data *data, int id)
{
	t_dongle	*node;

	node = dongle_new(id);
	if (!node)
		return (1);
	node->state.is_taken = 1;
	node->state.is_free = 0;
	node->state.is_cooldown = 2;
	dongle_add_back(&data->dongles, node);
	return (0);
}

int	init_dongle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->number_of_coders)
	{
		j = i + 1;
		if (init_one(data, j))
			return (1);
		i++;
	}
	return (0);
}