/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:33:32 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:36:25 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders(t_data *data)
{
	t_coder	*node;
	int		i;
	int		j;

	i = 0;
	while (i < data->number_of_coders)
	{
		j = i + 1;
		node = coder_new(data, j);
		if (!node)
			return (1);
		node->left = dongle_at(data, i);
		node->right = dongle_at(data, (j) % data->number_of_coders);
		node->last_compile_start = 0;
		node->data = data;
		coder_add_back(&data->coders, node);
		i++;
	}
	return (0);
}