/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:41:43 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/19 08:28:21 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	log_message(t_data *data, int coder_id, const char *msg)
{
	pthread_mutex_lock(&data->general_mutex);
	if (!data->stop)
		printf("%ld %d %s\n", get_elapsed_ms(data), coder_id, msg);
	pthread_mutex_unlock(&data->general_mutex);
}

void	log_error(void)
{
	fprintf(stderr, "[WARNING]: Arguments error\n");
}
