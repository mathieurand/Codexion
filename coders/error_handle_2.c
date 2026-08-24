/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:58:18 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/24 15:30:02 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	handle_n_coders(int *i)
{
	printf("%s[ERROR-%d]%s: Number of coders "
		"%scan't be negative%s\n",
		get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_tto_burnout(int *i)
{
	printf("%s[ERROR-%d]%s: Time to burnout "
		"%scan't be negative%s\n",
		get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_tto_comp(int *i)
{
	printf("%s[ERROR-%d]%s: Time to compile "
		"%scan't be negative%s\n", get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}

void	handle_tto_deg(int *i)
{
	printf("%s[ERROR-%d]%s: Time to debug "
		"%scan't be negative%s\n", get_color("red"), *i,
		get_color("reset"), get_color("blue"),
		get_color("reset"));
	(*i)++;
}
