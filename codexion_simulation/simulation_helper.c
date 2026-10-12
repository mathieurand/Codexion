/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 07:02:21 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/12 10:09:04 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	release_dongle(t_coder *coder)
{
	long	now;

	now = get_time_ms();
	pthread_mutex_lock(&coder->data->dongle_mutex);
	coder->left->state = 0;
	coder->left->release_at = now;
	coder->right->state = 0;
	coder->right->release_at = now;
	pthread_cond_broadcast(&coder->data->cond);
	pthread_mutex_unlock(&coder->data->dongle_mutex);
}

void	compile(t_coder *coder)
{
	long	i;

	take_dongle(coder);
	if (should_stop(coder->data))
		return ;
	pthread_mutex_lock(&coder->data->general_mutex);
	coder->last_compile_start = get_elapsed_ms(coder->data);
	pthread_mutex_unlock(&coder->data->general_mutex);
	log_message(coder->data, coder->id, "is compiling");
	i = get_time_ms();
	while (!should_stop(coder->data)
		&& get_time_ms() - i < coder->data->time_to_compile)
		usleep(1000);
	pthread_mutex_lock(&coder->data->general_mutex);
	coder->compiles_done++;
	pthread_mutex_unlock(&coder->data->general_mutex);
	release_dongle(coder);
}

void	debug(t_coder *coder)
{
	if (should_stop(coder->data) && get_time_ms() - coder->last_compile_start > coder->data->time_to_burnout)
		return ;
	log_message(coder->data, coder->id, "is debugging");
	usleep(coder->data->time_to_debug * 1000);
}

void	refactor(t_coder *coder)
{
	if (should_stop(coder->data) && get_time_ms() - coder->last_compile_start > coder->data->time_to_burnout)
		return ;
	log_message(coder->data, coder->id, "is refactoring");
	usleep(coder->data->time_to_refactor * 1000);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	wait_for_start(coder->data);
	while (coder->compiles_done < coder->data->compiles_required)
	{
		if (should_stop(coder->data))
			break ;
		compile(coder);
		if (should_stop(coder->data))
			break ;
		debug(coder);
		refactor(coder);
	}
	return (NULL);
}
