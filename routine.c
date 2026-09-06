/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 21:56:04 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/05 21:59:01 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*routine1(void *arg)
{
	t_coder	*coder;

	coder = (void *)arg;
	printf("hi i'm thread %d\n", coder->id);
	// usleep(5000);
	return (NULL);
}