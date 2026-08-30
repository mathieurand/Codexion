/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:50:18 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/30 18:06:33 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODERS_H
# define CODERS_H

typedef struct s_coder t_coder;
typedef struct s_dongle t_dongle;
typedef struct s_mutex t_mutex;

struct s_coder
{
	int			id;
	int 		time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			no_compreq;
	pthread_t	coder_th;
	t_mutex		*mutx;
};

struct s_mutex
{
	pthread_mutex_t mutx;
};

struct s_dongle
{
	int id;
	int cooldown;
	pthread_mutex_t	lock;
};

#endif