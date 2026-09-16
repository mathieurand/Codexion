/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:17:41 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:32:13 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->general_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->general_mutex);
		return (1);
	}
	if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->log_mutex);
		return (1);
	}
	if (pthread_mutex_init(&data->dongle_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->dongle_mutex);
		return (1);
	}
	return (0);
}