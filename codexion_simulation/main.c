/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 19:49:46 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/13 23:44:37 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	abort_start(t_data *data, int created)
{
	pthread_mutex_lock(&data->general_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->general_mutex);
	pthread_mutex_lock(&data->bar_mutex);
	data->start_signal = 1;
	pthread_cond_broadcast(&data->bar_cond);
	pthread_mutex_unlock(&data->bar_mutex);
	while (--created >= 0)
		pthread_join(data->coder[created].thread, NULL);
}

static int	main_helper(t_data *data)
{
	pthread_t	monitor;
	int			created;

	created = launch_pthread(data);
	if (created != data->nb_coders
		|| pthread_create(&monitor, NULL, monitor_routine, data))
	{
		abort_start(data, created);
		return (1);
	}
	if (join_thread(data))
		return (1);
	pthread_join(monitor, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	if (init_data(data, ac, av) != 0)
	{
		log_error();
		free(data);
		return (1);
	}
	if (init_dongle(data) || init_coder(data) || main_helper(data))
	{
		cleanup(data);
		return (1);
	}
	cleanup(data);
	return (0);
}
