/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:44:54 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 07:57:35 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	init_dongle_helper(t_dongle *dongle)
{
	dongle->waiters[0].active = 0;
	dongle->waiters[0].coder_id = 0;
	dongle->waiters[0].key = 0;
	dongle->waiters[1].active = 0;
	dongle->waiters[1].coder_id = 0;
	dongle->waiters[1].key = 0;
}

int	init_dongle(t_data *data)
{
	t_dongle	*dongle;
	int			nb;
	int			i;

	nb = data->nb_coders;
	if (nb == 0)
		return (1);
	dongle = malloc(sizeof(t_dongle) * nb);
	if (!dongle)
		return (1);
	i = 0;
	while (i < nb)
	{
		dongle[i].id = i + 1;
		dongle[i].state = 0;
		dongle[i].release_at = 0;
		init_dongle_helper(&dongle[i]);
		i++;
	}
	data->dongle = dongle;
	return (0);
}

int	init_coder(t_data *data)
{
	t_coder	*coder;
	int		nb;
	int		i;

	nb = data->nb_coders;
	if (nb == 0)
		return (1);
	coder = malloc(sizeof(t_coder) * nb);
	if (!coder)
		return (1);
	i = 0;
	while (i < nb)
	{
		coder[i].id = i + 1;
		coder[i].compiles_done = 0;
		coder[i].last_compile_start = 0;
		coder[i].data = data;
		coder[i].left = &data->dongle[i];
		coder[i].right = &data->dongle[(i + 1) % nb];
		i++;
	}
	data->coder = coder;
	return (0);
}
