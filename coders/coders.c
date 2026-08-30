/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:41:00 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/30 21:05:27 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "coders.h"
#include "codexion.h"

void	compile(t_coder *cod)
{
	printf("%d is compiling\n", cod->id);
	usleep(100000);
}

void	*routine_performs(void * arg)
{
	t_coder *coder;

	coder = (t_coder *)arg;
	pthread_mutex_lock(&coder->mutx->mutx);
	compile(coder);
	pthread_mutex_unlock(&coder->mutx->mutx);
	return (NULL);
}


void	set_id(t_coder **cd, int nb_cod)
{
	int	i;
	int j;

	j = 1;
	i = 0;
	while (i <= nb_cod)
	{
		cd[i]->id = j;
		j++;
		i++;
	}
}

void	set_coder_arg(t_coder *coder, t_arg *valid_arg)
{
	coder->time_to_burnout = valid_arg->tto_bout;
	coder->time_to_compile = valid_arg->tto_comp;
	coder->time_to_debug = valid_arg->tto_deg;
	coder->time_to_refactor = valid_arg->tto_refr;
	coder->no_compreq = valid_arg->no_compreq;
}


t_coder *create_coders(int	n, t_mutex *mutx)
{
	int		i;
	t_coder	*cod;

	cod = (t_coder *)malloc(sizeof(t_coder) * n);
	if (!cod)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cod[i].id = i + 1;
		cod[i].mutx = mutx;
		pthread_create(&cod[i].coder_th, NULL, routine_performs, &cod[i]);
		i++;
	}
	return (cod);
}

void join_coders(int n, t_coder *cod)
{
	int		i;

	i = 0;
	while (i < n)
	{
		pthread_join(cod[i].coder_th, NULL);
		i++;
	}
}



int main(int ac, char **av)
{
	t_mutex	mutx;
	t_coder	*coders;
	t_arg	arg;

	if (ac == 9)
	{
		if (!parser(&arg, av))
			return (0);
		if (pthread_mutex_init(&mutx.mutx, NULL) != 0)
			return (2);
		coders = create_coders(arg.n_coders, &mutx);
		if (!coders)
			return (1);
		join_coders(arg.n_coders, coders);	
		pthread_mutex_destroy(&mutx.mutx);
	}
	else
		printf("usage: ./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>\n");
	return (0);
}