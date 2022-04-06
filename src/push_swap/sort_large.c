/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:17 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 03:35:31 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int *arr, size_t chunk, size_t c)
{
	int	max;
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (chunk >= 1)
	{
		if (chunk == 1)
			max = arr[k];
		else
			max = arr[k];
		if (c == chunk)
			return (max);
		k = (i * S_NUM);
		i++;
		chunk--;
	}
	return (0);
}

int	get_min(int *arr, t_stack *a, size_t chunk, size_t c)
{
	int	min;
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (chunk >= 1)
	{
		if (chunk == 1)
			min = arr[k + ((a->top + 1) % k) - 1];
		else
			min = arr[i * S_NUM - 1];
		if (c == chunk)
			return (min);
		k = (i * S_NUM);
		i++;
		chunk--;
	}
	return (0);
}

void	pos(t_stack *a, t_stack *b)
{
	int	top_num;
	int	move;

	top_num = b->array[b->top];
	move = closest(a, top_num);
	if (move == top_num && a->top >= 0)
		move = find_smallest(a);
	get_top_a(a, move);
	run(a, b, PA);
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		best_pos(b, find_smallest(b), find_biggest(b));
		pos(a, b);
	}
}

int	solve_large(t_stack *a, t_stack *b)
{
	size_t	chunk;
	int		*arr;
	int		min;
	int		max;

	arr = correct_order(a);
	chunk = chunk_counter(a);
	while (chunk >= 1)
	{
		min = get_min(arr, a, chunk_counter(a), chunk);
		max = get_max(arr, chunk_counter(a), chunk);
		move_chunk(a, b, min, max);
		sort_chunk(a, b);
		chunk--;
	}
	get_top_a(a, find_smallest(a));
	return (0);
}
