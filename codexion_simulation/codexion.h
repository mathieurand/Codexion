/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:02:12 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/21 13:00:33 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# define _GNU_SOURCE
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_waiter	t_waiter;
typedef struct s_dongle	t_dongle;
typedef struct s_coder	t_coder;
typedef struct s_data	t_data;

struct s_waiter
{
	int		coder_id;
	long	key;
	int		active;
};

struct s_dongle
{
	int				id;
	int				state;
	long			release_at;
	t_waiter		waiters[2];
};

struct s_coder
{
	int			id;
	long		compiles_done;
	long		last_compile_start;
	pthread_t	thread;
	t_dongle	*left;
	t_dongle	*right;
	t_data		*data;
};

struct s_data
{
	long			nb_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	long			compiles_required;
	long			dongle_cooldown;
	int				scheduler;
	long			start_time;
	int				stop;
	long			timestamp;
	long			running;
	t_coder			*coder;
	t_dongle		*dongle;
	pthread_mutex_t	general_mutex;
	pthread_mutex_t	dongle_mutex;
	pthread_cond_t	cond;
	long			request_counter;
};

long	compute_key(t_coder *coder);
void	register_waiter(t_dongle *dongle, int coder_id, long key);
void	unregister_waiter(t_dongle *dongle, int coder_id);
int		is_top_priority(t_dongle *dongle, int coder_id, long my_key);
void	wait_until_ready(t_coder *coder);
int		dongle_ready(t_dongle *dongle, long cooldown, int coder_id, long key);
void	take_dongle(t_coder *coder);
int		should_stop(t_data *data);
void	refactor(t_coder *coder);
void	debug(t_coder *coder);
void	compile(t_coder *coder);
void	release_dongle(t_coder *coder);
void	*monitor_routine(void *arg);
void	log_message(t_data *data, int coder_id, const char *msg);
long	get_elapsed_ms(t_data *data);
long	get_time_ms(void);
int		init_dongle(t_data *data);
int		join_thread(t_data *data);
int		launch_pthread(t_data *data);
void	*coder_routine(void *arg);
int		init_data(t_data *data, int ac, char **av);
int		init_coder(t_data *data);
void	cleanup(t_data *data);
int		ft_atoi_safe(const char *str, long *out);

#endif
