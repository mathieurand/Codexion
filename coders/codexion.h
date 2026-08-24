/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:13:16 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/24 15:29:18 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_color	t_color;

struct s_data
{
	int		n_coders;
	int		tto_bout;
	int		tto_comp;
	int		tto_deg;
	int		tto_refr;
	int		no_compreq;
	int		dong_cooldown;
	char	*sched;
	void	(*__init__)(t_data *self, char **av);
	void	(*disp_data)(t_data *self);
};

struct s_color
{
	const char	*name;
	const char	*color;
};

int			ft_atoi(char *s);
int			parser(t_data *self, char *av[]);
int			ft_strcmp(const char *s1, const char *s2);
const char	*get_color(const char *color_name);
void		handle_n_coders(int *i);
void		handle_tto_burnout(int *i);
void		handle_tto_comp(int *i);
void		handle_tto_deg(int *i);
void		handle_tto_refr(int *i);
void		handle_no_compreq(int *i);
void		handle_dong_cooldown(int *i);
void		handle_sched(int *i);
void		handle_msg(t_data *self);
int			is_neg(int n);

#endif