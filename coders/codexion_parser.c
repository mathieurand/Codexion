/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 08:51:31 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/30 20:57:55 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	__init__(t_arg *self, char **av)
{
	self->n_coders = atoi(av[1]);
	self->tto_bout = atoi(av[2]);
	self->tto_comp = atoi(av[3]);
	self->tto_deg = atoi(av[4]);
	self->tto_refr = atoi(av[5]);
	self->no_compreq = atoi(av[6]);
	self->dong_cooldown = atoi(av[7]);
	self->sched = av[8];
}

int	is_neg(int n)
{
	return (n < 0);
}

int	parser(t_arg *self, char **av)
{
	__init__(self, av);
	self->__init__ = __init__;
	if (is_neg(self->n_coders) || is_neg(self->tto_bout)
		|| is_neg(self->tto_comp) || is_neg(self->tto_deg)
		|| is_neg(self->tto_refr) || is_neg(self->no_compreq)
		|| is_neg(self->dong_cooldown)
		|| (strcmp(self->sched, "fifo") != 0
			&& strcmp(self->sched, "edf") != 0))
	{
		handle_msg(self);
		return (0);
	}
	return (1);
}
