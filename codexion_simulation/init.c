/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:06:33 by tokyrand          #+#    #+#             */
/*   Updated: 2026/10/19 08:36:09 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (!av || av[0] == '\0')
		return (1);
	if ((av[i] == '-' || av[i] == '+') && strlen(av) >= 2)
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	has_forbiden_zero(char **av)
{
	long	value[8];
	int		i;

	i = 1;
	while (i < 8)
	{
		if (ft_atoi_safe(av[i], &value[i]))
			return (1);
		if (value[i] < 0)
		{
			return (1);
		}
		i++;
	}
	if (value[1] == 0)
		return (1);
	if (value[6] == 0)
		printf("compilation limit reached!\n");
	return (0);
}

static int	parsing(int ac, char **av)
{
	int	i;

	if (ac != 9)
		return (1);
	i = 1;
	while (i < 8)
	{
		if (is_number(av[i]) != 0)
			return (1);
		i++;
	}
	if (has_forbiden_zero(av))
		return (1);
	if (strcmp(av[8], "fifo") != 0
		&& strcmp(av[8], "edf") != 0)
		return (1);
	return (0);
}

static int	init_helper(t_data *data, char **av)
{
	if (!strcmp(av[8], "fifo"))
		data->scheduler = 1;
	else if (!strcmp(av[8], "edf"))
		data->scheduler = 0;
	data->timestamp = 0;
	data->request_counter = 0;
	data->stop = 0;
	data->threads_ready = 0;
	data->start_signal = 0;
	data->start_time = get_time_ms();
	if (pthread_mutex_init(&data->bar_mutex, NULL)
		|| pthread_cond_init(&data->bar_cond, NULL))
		return (1);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	if (parsing(ac, av))
		return (1);
	if (ft_atoi_safe(av[1], &data->nb_coders))
		return (1);
	if (ft_atoi_safe(av[2], &data->time_to_burnout))
		return (1);
	if (ft_atoi_safe(av[3], &data->time_to_compile))
		return (1);
	if (ft_atoi_safe(av[4], &data->time_to_debug))
		return (1);
	if (ft_atoi_safe(av[5], &data->time_to_refactor))
		return (1);
	if (ft_atoi_safe(av[6], &data->compiles_required))
		return (1);
	if (ft_atoi_safe(av[7], &data->dongle_cooldown))
		return (1);
	if (pthread_mutex_init(&data->general_mutex, NULL)
		|| pthread_mutex_init(&data->dongle_mutex, NULL)
		|| pthread_cond_init(&data->cond, NULL)
		|| init_helper(data, av))
		return (1);
	return (0);
}
