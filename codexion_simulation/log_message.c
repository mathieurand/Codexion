/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:41:43 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/20 14:16:25 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	log_message(t_data *data, int coder_id, const char *msg)
{
	pthread_mutex_lock(&data->general_mutex);
	printf("%ld %d %s\n", get_elapsed_ms(data), coder_id, msg);
	pthread_mutex_unlock(&data->general_mutex);
}
