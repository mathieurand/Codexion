/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:09:32 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/19 08:36:15 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	wait_for_start(t_data *data)
{
	pthread_mutex_lock(&data->bar_mutex);
	data->threads_ready++;
	if (data->threads_ready == data->nb_coders)
	{
		data->start_signal = 1;
		pthread_cond_broadcast(&data->bar_cond);
	}
	else
	{
		while (!data->start_signal)
			pthread_cond_wait(&data->bar_cond, &data->bar_mutex);
	}
	pthread_mutex_unlock(&data->bar_mutex);
}

int	waiter_is_blocked(t_data *data, int waiter_id, t_dongle *shared)
{
	t_coder	*w;

	w = &data->coder[waiter_id - 1];
	if (w->left == shared)
		return (w->right->state);
	return (w->left->state);
}