/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:17:30 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 03:18:00 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	move_top(t_stack *a, int min, int max)
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
	int	moves;

	moves = S_NUM;
	while (moves)
	{
		if (move_top(a, min, max) == -1)
			break ;
		run(a, b, PB);
		moves--;
	}
}
