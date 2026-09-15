/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 21:46:52 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 00:21:48 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_dongle	*init_dongle(char **av)
{
	t_dongle *dongle;
	int	i;
	int	j;

	i = 0;
	j = 1;
	dongle = malloc(sizeof(t_dongle) * atoi(av[1]));
	if (!dongle)
	{
		free(dongle);
		return (NULL);
	}
	while (i < atoi(av[1]))
	{
		dongle[i].id = j;
		i++;
		j++;
	}
	return (dongle);
}