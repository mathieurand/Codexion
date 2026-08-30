/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:49:21 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/29 00:59:00 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

const char	*get_color(const char *color_name)
{
	int		i;
	t_color	color[19];

	color[0] = (t_color){"black", "\033[30m"};
	color[1] = (t_color){"red", "\033[31m"};
	color[2] = (t_color){"green", "\033[32m"};
	color[3] = (t_color){"yellow", "\033[33m"};
	color[4] = (t_color){"blue", "\033[34m"};
	color[5] = (t_color){"magenta", "\033[35m"};
	color[6] = (t_color){"cyan", "\033[36m"};
	color[7] = (t_color){"white", "\033[37m"};
	color[8] = (t_color){"bright_black", "\033[90m"};
	color[9] = (t_color){"bright_red", "\033[91m"};
	color[10] = (t_color){"bright_green", "\033[92m"};
	color[11] = (t_color){"bright_yellow", "\033[93m"};
	color[12] = (t_color){"reset", "\033[0m"};
	i = 0;
	while (color[i].name != NULL)
	{
		if (strcmp(color[i].name, color_name) == 0)
			return (color[i].color);
		i++;
	}
	return (color[1].color);
}
