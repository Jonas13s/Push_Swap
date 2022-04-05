/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:17 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/05 17:59:24 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	chunk_counter(t_stack *a)
{
	size_t	count;

	count = (a->top + 1) / S_NUM + 1;
	return (count);
}

int	find_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->array[i] >= min && a->array[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

int	find_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (a->array[i] >= min && a->array[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

void	get_top_a(t_stack *a, int num)
{
	int	move;

	move = a->top;
	while (move >= 0 && a->array[move] != num)
		move--;
	if (move < 0)
		return ;
	if (move < a->top / 2)
		run_times(a, NULL, RRA, move + 1);
	else
		run_times(a, NULL, RA, a->top - move);
}

int move_top(t_stack *a, int min, int max)
{
	int	i;
	int	top;
	int	bot;

	top = -1;
	bot = -1;
	top = find_top(a, min, max);
	bot = find_bottom(a, min, max);
	if (top == -1 || bot == -1)
		return (-1);
	if (top < a->top - bot)
		i = top;
	else
		i = bot;
	get_top_a(a, a->array[i]);
	return (0);
}

void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int moves;

	moves = S_NUM;
	while(moves)
	{
		if (move_top(a, min, max) == -1)
			break ;
		run(a, b, PB);
		moves--;
	}
}

int get_max(int *arr, size_t chunk, size_t c)
{
	int	max;
	int	i;
	int	k;

	i = 1;
	k = 0;
	while(chunk >= 1)
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
int get_min(int *arr, t_stack *a, size_t chunk, size_t c)
{
	int	min;
	int	i;
	int	k;

	i = 1;
	k = 0;
	while(chunk >= 1)
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

int	closest(t_stack *a, int num)
{
	int	k;
	int	i;

	if (a->top < 0 || num > find_biggest(a))
		return (num);
	i = 0;
	k = find_biggest(a);
	while (i <= a->top)
	{
		if (a->array[i] > num && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

void	pos(t_stack *a, t_stack *b)
{
	int top_num;
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

int solve_large(t_stack *a, t_stack *b)
{
	size_t	chunk;
	int	*arr;

	arr = correct_order(a);
	chunk = chunk_counter(a);
	while(chunk >= 1)
	{
		printf("%d %d\n", get_max(arr, chunk_counter(a), chunk), get_min(arr, a, chunk_counter(a), chunk));
		move_chunk(a, b, get_min(arr, a, chunk_counter(a), chunk), get_max(arr, chunk_counter(a), chunk));
		sort_chunk(a, b);
		chunk--;
	}
	get_top_a(a, find_smallest(a));
	(void)a;
	(void)b;
	return (0);
}