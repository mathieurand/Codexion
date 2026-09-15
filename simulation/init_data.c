/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:10:28 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:13:50 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	parse_scheduler(t_data *data, const char *args)
{
	if (strcmp(args, "fifo") == 0)
	{
		data->scheduler = 0;
		return (0);
	}
	else if (strcmp(args, "edf") == 0)
	{
		data->scheduler = 1;
		return (0);
	}
	
	return (1);
}

static int	fill_value(t_data *data, long *v)
{
	if (v[0] < 1 || v[0] > 999)
		return (1);
	if (v[1] < 1 || v[2] < 0 || v[3] < 0 || v[4] < 0 || v[5] < 1 || v[6] < 0)
		return (1);
	data->number_of_coders = (int)v[0];
	data->time_to_burnout = v[1];
	data->time_to_compile = v[2];
	data->time_to_debug = v[3];
	data->time_to_refactor = v[4];
	data->compiles_required = (int)v[5];
	data->dongle_cooldown = v[6];
	return (0);
}

int	parse_and_valid_args(t_data *data, int argc, char **args)
{
	long	value[7];
	int		i;

	if (argc != 9)
		return (1);
	i = 0;
	while (i < 7)
	{
		if (!ft_isnumber(args[i + 1]))
			return (1);
		if (ft_atoi_strict(args[i + 1], &value[i]) != 0)
			return (1);
		i++;
	}
	if (fill_value(data, value) != 0)
		return (1);
	if (parse_scheduler(data, args[8]) != 0)
		return (1);
	if (init_mutex(data) != 0)
		return (1);
	return (0);	
}