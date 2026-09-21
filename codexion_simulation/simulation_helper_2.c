/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 07:04:53 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 10:56:27 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_top_priority(t_dongle *dongle, int coder_id, long my_key)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (dongle->waiters[i].active
			&& dongle->waiters[i].coder_id != coder_id)
		{
			if (dongle->waiters[i].key < my_key)
				return (1);
			if (dongle->waiters[i].key == my_key
				&& dongle->waiters[i].coder_id < coder_id)
				return (1);
		}
		i++;
	}
	return (0);
}

int	should_stop(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->general_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->general_mutex);
	return (stop);
}

long	compute_key(t_coder *coder)
{
	if (coder->data->scheduler == 1)
		return (++coder->data->request_counter);
	return (coder->last_compile_start + coder->data->time_to_burnout);
}

void	register_waiter(t_dongle *dongle, int coder_id, long key)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!dongle->waiters[i].active
			|| dongle->waiters[i].coder_id == coder_id)
		{
			dongle->waiters[i].coder_id = coder_id;
			dongle->waiters[i].key = key;
			dongle->waiters[i].active = 1;
			return ;
		}
		i++;
	}
}

void	unregister_waiter(t_dongle *dongle, int coder_id)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (dongle->waiters[i].active
			&& dongle->waiters[i].coder_id == coder_id)
			dongle->waiters[i].active = 0;
		i++;
	}
}
