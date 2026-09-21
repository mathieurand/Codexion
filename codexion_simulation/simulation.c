/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:28:15 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 09:09:49 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	wait_until_ready(t_coder *coder)
{
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_nsec += 5 * 1000000;
	if (ts.tv_nsec > 1000000000)
	{
		ts.tv_sec += 1;
		ts.tv_nsec -= 1000000000;
	}
	pthread_cond_timedwait(&coder->data->cond, &coder->data->dongle_mutex, &ts);
}

int	dongle_ready(t_dongle *dongle, long cooldown, int coder_id, long key)
{
	if (dongle->state)
		return (1);
	if (get_time_ms() - dongle->release_at < cooldown)
		return (1);
	if (is_top_priority(dongle, coder_id, key))
		return (1);
	return (0);
}

static void	wait_and_register_both(t_coder *coder, long cooldown, long key)
{
	register_waiter(coder->left, coder->id, key);
	register_waiter(coder->right, coder->id, key);
	while ((dongle_ready(coder->left, cooldown, coder->id, key)
			|| dongle_ready(coder->right, cooldown, coder->id, key))
		&& !should_stop(coder->data))
		wait_until_ready(coder);
	unregister_waiter(coder->left, coder->id);
	unregister_waiter(coder->right, coder->id);
}

static void	active_state_dongle(t_coder *coder)
{
	coder->left->state = 1;
	coder->right->state = 1;
}

void	take_dongle(t_coder *coder)
{
	long	cooldown;
	long	key;

	if (coder->left == coder->right)
	{
		log_message(coder->data, coder->id, "has taken a dongle");
		while (!should_stop(coder->data))
			usleep(1000);
		return ;
	}
	cooldown = coder->data->dongle_cooldown;
	pthread_mutex_lock(&coder->data->dongle_mutex);
	key = compute_key(coder);
	wait_and_register_both(coder, cooldown, key);
	if (should_stop(coder->data))
	{
		pthread_mutex_unlock(&coder->data->dongle_mutex);
		return ;
	}
	active_state_dongle(coder);
	pthread_mutex_unlock(&coder->data->dongle_mutex);
	log_message(coder->data, coder->id, "has taken a dongle");
	log_message(coder->data, coder->id, "has taken a dongle");
}
