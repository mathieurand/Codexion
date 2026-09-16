/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:33:49 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 05:44:31 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int ac, char **av)
{
	t_data	data;
	int		error;

	memset(&data, 0, sizeof(t_data));
	if (parse_and_valid_args(&data, ac, av) != 0)
	{
		error = ft_error("usage: ./codexion number_of_coders time_to_burnout "
				"time_to_compile time_to_debug time_to_refactor "
				"number_of_compiles_required dongle_cooldown fifo|edf");
		return (error);
	}
	if (init_dongle(&data))
	{
		error = ft_error("coders not initialized!");
		return (error);
	}
	if (init_coders(&data))
	{
		error = ft_error("coders not initialized!");
		return (error);
	}
	int i = 0;
	while (data.coders && i < data.number_of_coders)
	{
		printf("coder: %d\n\tleft dongle:\t%d\n\tright dongle:\t%d\n", data.coders->id, data.coders->left->id, data.coders->right->id);
		data.coders = data.coders->next;
		i++;
	}
	return (0);
}
