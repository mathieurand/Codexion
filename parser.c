/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 21:44:18 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/06 06:29:04 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static bool	check_number_coder(char *av)
{
	if (atoi(av) == 0)
	{
		printf("[WARNING]: number of coder can't be zero\n");
		return (false);
	}
	return (true);
}

static t_error *error_msg(t_error *error)
{
	error->msg = (char **)malloc(sizeof(char *) * 8);
	error->msg[0] = "number of coder";
	error->msg[1] = "time to burnout";
	error->msg[2] = "time to compile";
	error->msg[3] = "time to debug";
	error->msg[4] = "time to refractor";
	error->msg[5] = "dongle cooldown";
	error->msg[6] = "number of compile required";
	error->msg[7] = "scheduler";
	return (error);
}

bool parser(char **av)
{
	t_error	*error;
	int	i;
	bool	an_error;
	int	j;

	error = NULL;
	error = malloc(sizeof(t_error));
	error = error_msg(error);
	an_error = true;
	if (!check_number_coder(av[1]))
		an_error = false;
	i = 1;
	j = 1;
	while (i < 8)
	{
		if (atoi(av[i]) < 0)
		{
			printf("[WARNING-%d-%s]: paramater can't be negative '%d'\n",
				j, error->msg[i - 1], atoi(av[i]));
			j++;
			an_error = false;
		}
		i++;
	}
	if ((strcmp(av[8], "fifo") != 0) && (strcmp(av[8], "edf") != 0))
	{
		printf("[WARNING-%d-%s]: got = '%d', expected 'fifo' or 'edf'\n",
			j, error->msg[i - 1], atoi(av[i]));		
		an_error = false;	
	}
	free(error->msg);
	free(error);
	return (an_error);
}