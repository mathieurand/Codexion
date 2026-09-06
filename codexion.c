/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:27:02 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/06 06:25:21 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void join_thread(t_coder *coder, char **av)
{
	int	i;

	i = 0;
	while (i < atoi(av[1]))
	{
		pthread_join(coder[i].coders_threads, NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	t_dongle	*dongle;
	t_coder		*coder;

	if (ac != 9)
	{
		printf("\033[31m");
		printf("  ______                   __                      __                     \n");
		printf(" /      \\                 |  \\                    |  \\                    \n");
		printf("|  \033[34m$$$$$$\033[0m\033[31m\\  ______    ____|\033[0m $$  ______   __    __  \\$$  ______   _______ \n");
		printf("\033[31m| \033[0m\033[34m$$   \\$$ /      \\  /      $$ /      \\ |  \\  /  \\|  \\ /      \\ |       \\\n");
		printf("\033[31m| \033[0m\033[34m$$      |  $$$$$$\\|  $$$$$$$|  $$$$$$\\ \\$$\\/  $$| $$|  $$$$$$\\| $$$$$$$\\\n");
		printf("\033[31m| \033[0m\033[34m$$   __ | $$  | $$| $$  | $$| $$    $$  >$$  $$ | $$| $$  | $$| $$  | $$\n");
		printf("\033[31m| \033[0m\033[34m$$__/  \\| $$__/ $$| $$__| $$| $$$$$$$$ /  $$$$\\ | $$| $$__/ $$| $$  | $$\n");
		printf("\033[31m \\\033[0m\033[34m$$    $$ \\$$    $$ \\$$    $$ \\$$     \\|  $$ \\$$\\| $$ \\$$    $$| $$  | $$\n");
		printf("\033[31m  \\\033[0m\033[34m$$$$$$   \\$$$$$$   \\$$$$$$$  \\$$$$$$$ \\$$   \\$$ \\$$  \\$$$$$$  \\$$   \\$$\n");
		printf("\n\n\n\033[0m");
		printf("[ERROR-USAGE]:\n");
		printf("usage: ./codexion <number_of_coders> <time_to_burnout>"
			" <time_to_compile> <time_to_debug> <time_to_refactor> "
			" <number_of_compiles_required> <dongle_cooldown> <scheduler>\n");
		return (0);
	}
	if (!parser(av))
		return (0);
	dongle = init_dongle(av);
	coder = init_coder(dongle, av);
	join_thread(coder, av);
	free(coder);
	free(dongle);
	return (0);
}
