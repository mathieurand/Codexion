/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 06:19:24 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 13:01:11 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	overflow(int *i, int *sign, char c)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi_safe(const char *str, long *out)
{
	long	res;
	int		sign;
	int		i;
	int		digit;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	overflow(&i, &sign, str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (sign == 1 && res > (2147483647L - digit) / 10)
			return (1);
		if (sign == -1 && res > (2147483648L - digit) / 10)
			return (1);
		res = res * 10 + digit;
		i++;
	}
	*out = res * sign;
	return (0);
}

int	launch_pthread(t_data *data)
{
	t_coder	*coder;
	int		i;
	int		nb;

	coder = data->coder;
	nb = (int)data->nb_coders;
	data->running = 0;
	i = 0;
	while (i < nb)
	{
		if (pthread_create(&coder[i].thread, NULL, coder_routine, &coder[i]))
			return (1);
		i++;
		data->running++;
	}
	return (0);
}

int	join_thread(t_data *data)
{
	t_coder	*coder;
	int		i;
	int		nb;

	coder = data->coder;
	nb = (int)data->nb_coders;
	i = 0;
	while (i < nb)
	{
		if (pthread_join(coder[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
