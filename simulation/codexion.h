/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:50:00 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 01:20:40 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_data	t_data;
typedef struct s_coder	t_coder;
typedef struct s_dongle	t_dongle;

struct s_dongle
{
	int				id;
	struct s_dongle *next;
};

struct s_coder
{
	int					id;
	pthread_t			thread;
	struct s_coder		*next;
};

struct s_data
{
	int					number_of_coders;
	long				time_to_burnout;
	long				time_to_compile;
	long				time_to_debug;
	long				time_to_refactor;
	int					compiles_required;
	long				dongle_cooldown;
	int					scheduler;
	pthread_mutex_t		log_mutex;
	pthread_mutex_t		general_mutex;
	pthread_mutex_t		dongle_mutex;
};

int	parse_and_valid_args(t_data *data, int argc, char **args);
int	ft_atoi_strict(const char *str, long *out);
int	init_mutex(t_data *data);

#endif