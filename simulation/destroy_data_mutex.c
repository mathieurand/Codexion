/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:20:43 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:23:47 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	destroy_mutex(t_data *data)
{
	if (pthread_mutex_destroy(&data->general_mutex) != 0)
		return (1);
	if (pthread_mutex_destroy(&data->dongle_mutex) != 0)
		return (1);
	if (pthread_mutex_destroy(&data->log_mutex) != 0)
		return (1);
	return (0);
}