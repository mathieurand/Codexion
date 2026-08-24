/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:21:59 by tokyrand          #+#    #+#             */
/*   Updated: 2026/08/24 15:18:05 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_num(char c)
{
	return (c >= '0' || c <= '9');
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((int)((*s1 - *s2)));
}

int	ft_atoi(char *s)
{
	int	res;
	int	i;
	int	len_s;

	res = 0;
	i = 0;
	len_s = ft_strlen(s);
	while (is_num(s[i]) && i < len_s)
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}
