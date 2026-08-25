/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:32:21 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/25 07:04:55 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	handle_msg(t_data *self)
{
	int	num;

	num = 1;
	if (is_neg(self->n_coders))
		handle_n_coders(&num);
	if (is_neg(self->tto_bout))
		handle_tto_burnout(&num);
	if (is_neg(self->tto_comp))
		handle_tto_comp(&num);
	if (is_neg(self->tto_deg))
		handle_tto_deg(&num);
	if (is_neg(self->tto_refr))
		handle_tto_refr(&num);
	if (is_neg(self->no_compreq))
		handle_no_compreq(&num);
	if (is_neg(self->dong_cooldown))
		handle_dong_cooldown(&num);
	if (ft_strcmp(self->sched, "fifo") != 0
		&& ft_strcmp(self->sched, "edf") != 0)
		handle_sched(&num);
}

void	handle_tto_refr(int *num)
{
	printf("%s[ERROR-%d]%s: Time to refractor "
		"%scan't be negative%s\n", get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_no_compreq(int *num)
{
	printf("%s[ERROR-%d]%s: Number of compiles required "
		"%scan't be negative%s\n",
		get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_dong_cooldown(int *num)
{
	printf("%s[ERROR-%d]%s: Dongle cooldown "
		"%scan't be negative%s\n",
		get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_sched(int *num)
{
	printf("%s[ERROR-%d]%s: Scheduler value must be "
		"%sfifo%s or %sedf%s\n",
		get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}
