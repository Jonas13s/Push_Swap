/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:30:59 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 02:31:11 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dup_check(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[++j])
		{
			if (i == j)
				continue ;
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
		}
	}
	return (0);
}

static int	check_size(char *str)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (str[++i])
	{
		if (str[i] == '-' && i == 0)
			continue ;
		size += str[i];
	}
	if (str[0] == '-' && size <= 527)
		return (0);
	if (size <= 526)
		return (0);
	return (1);
}

int	check_number(char **str, int args)
{
	int		i;
	int		j;

	if (args <= 1)
		return (1);
	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		if (check_size(str[i]))
			return (1);
	}
	if (dup_check(str))
		return (1);
	return (0);
}
