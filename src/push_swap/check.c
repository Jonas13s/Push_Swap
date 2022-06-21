/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:30:59 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/21 19:03:05 by joivanau         ###   ########.fr       */
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
	if (str[0] == '-' && ft_strcmp("2147483648", str) > 0)
		return (0);
	else if (ft_strcmp("2147483648", str) > 0)
		return (0);
	return (1);
}

int	check_number(char **str, int args, int mode)
{
	int		i;
	int		j;

	if (args <= 1)
		return (1);
	i = 0;
	if (mode == 1)
		i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' && j == 0 && str[i][j + 1] != '\0')
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

int	check_order(t_stack *a)
{
	int	i;

	i = a->top;
	while (i >= 1)
	{
		if (a->array[i] > a->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
