/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 03:12:53 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/12 10:14:03 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	is_stopped(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->general_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->general_mutex);
	return (stop);
}

static void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->general_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->general_mutex);
}

static int	all_compiles_done(t_data *data)
{
	int	i;
	int	done;

	i = 0;
	pthread_mutex_lock(&data->general_mutex);
	while (i < data->nb_coders)
	{
		if (data->coder[i].compiles_done < data->compiles_required)
		{
			pthread_mutex_unlock(&data->general_mutex);
			return (0);
		}
		i++;
	}
	done = 1;
	pthread_mutex_unlock(&data->general_mutex);
	return (done);
}

static int	check_burnout(t_data *data)
{
	int		i;
	long	now;
	long	start;

	i = 0;
	while (i < data->nb_coders)
	{
		pthread_mutex_lock(&data->general_mutex);
		start = data->coder[i].last_compile_start;
		pthread_mutex_unlock(&data->general_mutex);
		now = get_elapsed_ms(data);
		if (now - start >= data->time_to_burnout
			&& data->coder[i].compiles_done < data->compiles_required)
		{
			log_message(data, data->coder[i].id, "burned out");
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!is_stopped(data))
	{
		if (check_burnout(data))
		{
			set_stop(data);
			pthread_mutex_lock(&data->dongle_mutex);
			pthread_cond_broadcast(&data->cond);
			pthread_mutex_unlock(&data->dongle_mutex);
			return (NULL);
		}
		if (all_compiles_done(data))
		{
			set_stop(data);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
