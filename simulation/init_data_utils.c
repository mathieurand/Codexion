/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:14:35 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:16:04 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_atoi_strict(const char *str, long *out)
{
	long	value;
	int		i;

	value = 0;
	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		value = value * 10 + (str[i] - '0');
		if (value > 2147483647)
			return (1);
		i++;
	}
	*out = value;
	return (0);
}