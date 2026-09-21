/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:06:18 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 06:59:04 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	cleanup(t_data *data)
{
	pthread_mutex_destroy(&data->dongle_mutex);
	pthread_cond_destroy(&data->cond);
	pthread_mutex_destroy(&data->general_mutex);
	free(data->coder);
	free(data->dongle);
	free(data);
}
