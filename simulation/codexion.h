/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:50:00 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/16 06:01:20 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data			t_data;
typedef struct s_coder			t_coder;
typedef struct s_dongle			t_dongle;
typedef struct s_dongle_state	t_dongle_state;

struct s_dongle_state
{
	int			is_free;
	int			is_taken;
	int			is_cooldown;
	t_dongle	*dongle;
};

struct s_dongle
{
	int				id;
	t_dongle_state	state;
	int				released_at;
	struct s_dongle *next;
};

struct s_coder
{
	int					id;
	pthread_t			thread;
	t_dongle			*left;
	t_dongle			*right;
	long				last_compile_start;
	int					compiles_done;
	t_data				*data;
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
	t_coder				*coders;
	t_dongle			*dongles;
};

t_dongle	*dongle_at(t_data *data, int index);
void	dongle_add_back(t_dongle **lst, t_dongle *node);
t_dongle	*dongle_new(int id);

int		ft_error(const char *msg);
int		ft_atoi_strict(const char *str, long *out);
int		init_mutex(t_data *data);
int		destroy_mutex(t_data *data);
int		ft_isnumber(const char *str);

int		init_coders(t_data *data);

t_coder	*coder_new(t_data *data, int id);
void	coder_add_back(t_coder **lst, t_coder *node);

int	init_dongle(t_data *data);
int		parse_and_valid_args(t_data *data, int argc, char **args);


#endif