/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:13:16 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/30 21:06:24 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_arg	t_arg;
typedef struct s_color	t_color;

struct s_arg
{
	int		n_coders;
	int		tto_bout;
	int		tto_comp;
	int		tto_deg;
	int		tto_refr;
	int		no_compreq;
	int		dong_cooldown;
	char	*sched;
	void	(*__init__)(t_arg *self, char **av);
};

struct s_color
{
	const char	*name;
	const char	*color;
};

int			parser(t_arg *self, char *av[]);
const char	*get_color(const char *color_name);
void		handle_n_coders(int *i);
void		handle_tto_burnout(int *i);
void		handle_tto_comp(int *i);
void		handle_tto_deg(int *i);
void		handle_tto_refr(int *i);
void		handle_no_compreq(int *i);
void		handle_dong_cooldown(int *i);
void		handle_sched(int *i);
void		handle_msg(t_arg *self);
int			is_neg(int n);

#endif