/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:00:23 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/16 23:51:03 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_number_push(t_stack *s, int *group, int i, int number)
{
	int	moves;
	int	cmoves;

	if (number > s->top / 2)
		moves = s->top - number;
	else
		moves = number + 2;
	while (--i >= 0)
	{
		if (s->array[i] >= group[0] && s->array[i] <= group[1])
		{
			cmoves = i + 2;
			if (i > s->top / 2)
				cmoves = s->top - i;
			if (moves > cmoves || (moves == cmoves && \
			s->array[number] > s->array[i]))
			{
				number = i;
				moves = cmoves;
			}
		}
	}
	return (number);
}

int	has_group(t_stack *s, int *group)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{
		if (s->array[i] >= group[0] && s->array[i] <= group[1])
			return (1);
		i--;
	}
	return (0);
}

void	push_group(t_stack *a, t_stack *b, int *group)
{
	int	num;
	int	i;
	int	k;

	while (a->top > 1 && has_group(a, group))
	{
		k = a->top;
		while (k >= 0 && (a->array[k] < group[0] || a->array[k] > group[1]))
			k--;
		i = get_number_push(a, group, k, k);
		num = a->array[i];
		while (i > a->top / 2 && a->array[a->top] != num)
			run(a, b, RA);
		while (i <= a->top / 2 && a->array[a->top] != num)
			run(a, b, RRA);
		run(a, b, PB);
	}
}

static void	fill_group(int **groups, int smallest, int biggest, int num)
{
	int	i;

	i = 1;
	if (i <= num)
	{
		groups[i][0] = smallest;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / num);
	}
	while (++i < num)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / num);
	}
	if (i == num)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = biggest;
	}
}

int	**int_groups(t_stack *s, int num)
{
	int	**groups;
	int	smallest;
	int	biggest;
	int	i;

	smallest = find_smallest(s);
	biggest = find_biggest(s);
	groups = (int **) malloc(sizeof(int *) * (num + 1));
	if (!groups)
		return (NULL);
	i = 0;
	groups[i] = (int *) malloc(sizeof(int));
	if (!groups[i])
		return (NULL);
	groups[i][0] = num;
	while (++i <= num)
	{
		groups[i] = (int *) malloc(sizeof(int) * 2);
		if (!groups[i])
			return (NULL);
	}
	fill_group(groups, smallest, biggest, num);
	return (groups);
}
