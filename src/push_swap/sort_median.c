/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:59:14 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 15:35:43 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_below(t_stack *a, t_stack *b, int med)
{
	int	i;
	int	o;

	while (1)
	{
		o = a->top + 1;
		i = -1;
		while (++i <= a->top)
			if (a->array[i] <= med)
				break ;
		while (--o != -1)
			if (a->array[o] <= med)
				break ;
		if (a->array[o] > med || a->array[i] > med)
			return ;
		if ((a->top - o) >= i + 1)
			best_move_a(a, a->array[i]);
		else
			best_move_a(a, a->array[o]);
		if (a->array[a->top] > med)
			return ;
		run(a, b, PB);
	}
}

void	push_above(t_stack *a, t_stack *b, int med)
{
	int	i;
	int	o;

	while (1)
	{
		o = a->top + 1;
		i = -1;
		while (++i <= a->top)
			if (a->array[i] > med)
				break ;
		while (--o != -1)
			if (a->array[o] > med)
				break ;
		if (a->array[i] <= med || a->array[o] <= med)
			return ;
		if ((a->top - o) >= i + 1)
			best_move_a(a, a->array[i]);
		else
			best_move_a(a, a->array[o]);
		if (a->array[a->top] <= med)
			return ;
		run(a, b, PB);
	}
}

int	best_pos(t_stack *s, int small, int big)
{
	int	t[2];
	int	b[2];

	t[0] = best_move_top(s, small);
	t[1] = best_move_top(s, big);
	b[0] = best_move_bottom(s, small) + 1;
	b[1] = best_move_bottom(s, big) + 1;
	if ((t[0] <= t[1] && t[0] <= b[1]) || (b[0] <= b[1] && b[0] <= t[1]))
	{
		best_move_b(s, small);
		return (1);
	}
	else
	{
		best_move_b(s, big);
		return (2);
	}
	return (0);
}

void	push_back(t_stack *a, t_stack *b)
{
	int	k;
	int	count;

	count = 0;
	while (b->top >= 0)
	{
		k = best_pos(b, find_smallest(b), find_biggest(b));
		run(a, b, PA);
		if (k == 1)
			run(a, b, RA);
		else
			count++;
	}
	while (count != 0)
	{
		run(a, b, RA);
		count--;
	}
}

int	solve_median(t_stack *a, t_stack *b)
{
	int	med;

	med = median(a);
	push_below(a, b, med);
	push_back(a, b);
	push_above(a, b, med);
	push_back(a, b);
	return (0);
}
