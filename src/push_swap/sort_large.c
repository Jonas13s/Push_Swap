/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:17 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/04 18:45:01 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_counter(t_stack *a)
{
	int	i;
	int	count;

	count = 0;
	i = a->top;
	while(i >= 0)
	{
		i = i - S_NUM;
		count++;
	}
	return (count);
}

void find_value(t_stack *a, int *min, int *max, int chunk)
{
	int	*arr;

	arr = correct_order(a);
	*min = arr[a->top - (chunk * S_NUM)];
	if (a->top - (chunk * S_NUM) - 19 >= 0)
		*max = arr[a->top - (chunk * S_NUM) - 19];
	else
		*max = arr[0];
	free(arr);
}

int	next_closet(t_stack *s, int num)
{
	int	i;
	int max;

	max = find_biggest(s);
	i = 0;
	while (i <= s->top)
	{
		if (s->array[i] > num && num < max)
			max = s->array[i];
		i++;
	}
	return (max);
}

int	best_pos(t_stack *b, int small, int big)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while(++i <= b->top)
		if (b->array[i] == small || b->array[i] == big)
			break ;
	while(++k <= b->top)
		if (b->array[b->top - k] == small || b->array[i] == big)
			break ;
	if (k == 0)
		return (big);
	if (k <= (i + 1))
		return (big);
	else
		return (small);
	return (0);	
}

void	push_chunk(t_stack *a, t_stack *b, int *min_max, int chunk)
{
	int	i;
	int k;
	int	count;

	count = S_NUM;
	if (a->top - (chunk * S_NUM) < S_NUM)
		count = a->top - (chunk * S_NUM);
	while (count >= 0)
	{
		k = -1;
		i = -1;
		while (++i <= S_NUM)
			if (a->array[i] >= min_max[0] && a->array[i] <= min_max[1])
				break ;
		while (++k <= S_NUM)
			if (a->array[a->top - k] >= min_max[0] && a->array[a->top - k] <= min_max[1])
				break ;
		if (k == 0)
			get_top(a, a->array[a->top - k], 'a');
		else if (k <= i)
			get_top(a, a->array[a->top - k], 'a');
		else if (i < k)
			get_top(a, a->array[i], 'a');
		run(a, b, PB);
		count--;
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	best_num;
	int	big;
	int	small;
	int	count;

	count = 0;
	while (b->top != -1)
	{
		big = find_biggest(b);
		small = find_smallest(b);
		best_num = best_pos(b, small, big);
		if (best_num == big)
		{
			get_top(b, big, 'b');
			run(a, b, PA);
		}
		else if (best_num == small)
		{
			get_top(b, small, 'b');
			run(a, b, PA);
			run(a, b, RA);
			count++;
		}

	}
	while(--count != -1)
		run(a, b, RRA);
}

int	pos(t_stack *a, t_stack *b)
{
	int	top_b;
	int to_move;

	top_b = b->array[b->top];
	to_move = next_closet(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = find_smallest(a);
	get_top(a, to_move, 'a');
	run(a, b, PA);
	return (0);
}

int	solve_large(t_stack *a, t_stack *b)
{
	int	chunk;
	int	i;
	int	min_max[20][3];

	chunk = chunk_counter(a);
	i = -1;
	while(++i != chunk)
		find_value(a, &min_max[i][0], &min_max[i][1], i);
	i = chunk;
	while (i != 0)
	{
		//count = S_NUM;
		//if (chunk == 1 && a->top - (chunk * S_NUM) != 0)
			//count = (a->top + 1) % ((chunk_counter(a) - 1) * 20);
		ft_printf("%d %d\n", min_max[i][0] , min_max[i][1]);
		push_chunk(a, b, min_max[i], i);
		push_back(a, b);
		//ft_printf("\n\n\n\n\n");
		//get_top(a, next_closet(b, find_smallest(b)), 'a');
		//ft_printf("%d %d %d\n", min, max, i);
		i++;
	}
	(void)b;
	return (0);
}