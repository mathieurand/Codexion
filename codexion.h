/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:08:26 by tokyrand          #+#    #+#             */
/*   Updated: 2026/09/05 21:58:14 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_dongle	t_dongle;
typedef struct s_coder	t_coder;
typedef	struct s_error	t_error;

struct s_error
{
	char	**msg;
};

struct s_dongle
{
	int		id;
};

struct s_coder
{
	int			id;
	pthread_t	coders_threads;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_coder		*next;
	t_coder		*prev;
};

t_coder		*init_coder(t_dongle	*dongle, char **av);
bool		parser(char **av);
t_dongle	*init_dongle(char **av);
void		*routine1(void *arg);


#endif
