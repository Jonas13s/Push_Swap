/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:27:49 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/01 04:28:14 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i - 1]) < ft_atoi(argv[i]))
			count++;
		else
			return (0);
		i++;
	}
	if (count + 1 == i)
		return (1);
	return (0);
}

int	find_smallest(t_stack *s)
{
	int	i;
	int	number;

	i = 0;
	if (s->top == -1)
		return (1);
	number = s->array[0];
	while (i <= s->top)
	{
		if (s->array[i] < number)
			number = s->array[i];
		i++;
	}
	return (number);
}

int	find_biggest(t_stack *s)
{
	int	i;
	int	number;

	i = 0;
	if (s->top == -1)
		return (1);
	number = s->array[0];
	while (i <= s->top)
	{
		if (s->array[i] > number)
			number = s->array[i];
		i++;
	}
	return (number);
}

int	get_top(t_stack *s, int num, char c)
{
	int	i;

	if (s->top == -1)
		return (1);
	i = -1;
	while (++i <= s->top)
		if (s->array[i] == num)
			break ;
	if (s->array[i] != num)
		return (-1);
	best_move(s, c, num);
	return (0);
}