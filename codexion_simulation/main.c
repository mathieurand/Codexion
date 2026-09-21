/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 19:49:46 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 06:57:47 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	main_helper(t_data *data)
{
	pthread_t	monitor;

	if (launch_pthread(data))
	{
		cleanup(data);
		return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data))
	{
		cleanup(data);
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
	if (init_data(data, ac, av) != 0 || init_dongle(data))
	{
		free(data);
		return (1);
	}
	if (init_coder(data) != 0)
	{
		free(data->dongle);
		free(data);
		return (1);
	}
	if (main_helper(data))
		return (1);
	cleanup(data);
	return (0);
}
