/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 21:41:20 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/05 21:53:22 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


static t_coder	*init_help_coder(t_coder *coder, t_dongle *dongle)
{
	int	i;
	int j;
	int	k;

	i = 0;
	while (i < 4)
	{
		if (i != 3)
			j = i + 1;
		else
			j = 0;
		if (i != 0)
			k = i - 1;
		else
			k = 3;
		coder[i].prev = &coder[k];
		coder[i].next = &coder[j];
		coder[i].left_dongle = &dongle[k];
		coder[i].right_dongle = &dongle[j];
		i++;
	}
	return (coder);
}

t_coder	*init_coder(t_dongle	*dongle, char **av)
{
	t_coder *coder;

	coder = malloc(sizeof(t_coder) * atoi(av[1]));
	int	i, j;

	i = 0;
	j = 1;
	while (i < atoi(av[1]))
	{
		coder[i].id = j;
		coder[i].next = NULL;
		coder[i].prev = NULL;
		i++;
		j++;
	}
	i = 0;
	coder = init_help_coder(coder, dongle);
	i = 0;
	while (i < atoi(av[1]))
	{
		pthread_create(&coder[i].coders_threads, NULL, routine1, &coder[i]);
		i++;
	}
	return (coder);
}
