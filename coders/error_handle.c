/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:32:21 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/24 16:05:31 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	handle_msg(t_data *self)
{
	int	i;

	i = 1;
	if (is_neg(self->n_coders))
		handle_n_coders(&i);
	if (is_neg(self->tto_bout))
		handle_tto_burnout(&i);
	if (is_neg(self->tto_comp))
		handle_tto_comp(&i);
	if (is_neg(self->tto_deg))
		handle_tto_deg(&i);
	if (is_neg(self->tto_refr))
		handle_tto_refr(&i);
	if (is_neg(self->no_compreq))
		handle_no_compreq(&i);
	if (is_neg(self->dong_cooldown))
		handle_dong_cooldown(&i);
	if (ft_strcmp(self->sched, "fifo") != 0
		&& ft_strcmp(self->sched, "edf") != 0)
		handle_sched(&i);
}

void	handle_tto_refr(int *i)
{
	printf("%s[ERROR-%d]%s: Time to refractor "
		"%scan't be negative%s\n", get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_no_compreq(int *i)
{
	printf("%s[ERROR-%d]%s: Number of compiles required "
		"%scan't be negative%s\n",
		get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_dong_cooldown(int *i)
{
	printf("%s[ERROR-%d]%s: Dongle cooldown "
		"%scan't be negative%s\n",
		get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_sched(int *i)
{
	printf("%s[ERROR-%d]%s: Scheduler value must be "
		"%sfifo%s or %sedf%s\n",
		get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}
