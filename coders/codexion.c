/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 23:11:55 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/24 14:16:49 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "codexion.h"

int	main(int ac, char *av[])
{
	t_data	t1;

	if (ac == 9)
	{
		if (!parser(&t1, av))
		{
			return (0);
		}
		printf("OK\n");
	}
	else
		printf("ac = %d", ac);
	return (0);
}
