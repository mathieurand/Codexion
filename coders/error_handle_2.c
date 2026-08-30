/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:58:18 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/28 22:29:57 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	handle_n_coders(int *num)
{
	printf("%s[ERROR-%d]%s: Number of coders "
		"%scan't be negative or 0%s\n",
		get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_tto_burnout(int *num)
{
	printf("%s[ERROR-%d]%s: Time to burnout "
		"%scan't be negative or 0%s\n",
		get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_tto_comp(int *num)
{
	printf("%s[ERROR-%d]%s: Time to compile "
		"%scan't be negative or 0%s\n", get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}

void	handle_tto_deg(int *num)
{
	printf("%s[ERROR-%d]%s: Time to debug "
		"%scan't be negative or 0%s\n", get_color("red"), *num,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*num)++;
}
