/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:56:43 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/17 12:44:27 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_counter(t_stack *a, t_stack *b, int number, int bond[2])
{
	int	i;

	i = a->top;
	while (b->array[number] > bond[0] && b->array[number] < bond[1] && i > 0 && \
	(b->array[number] < a->array[i] || b->array[number] > a->array[i - 1]))
		i--;
	while ((b->array[number] < bond[0] || b->array[number] > bond[1]) && \
	i >= 0 && a->array[i] != bond[1])
		i--;
	return (i);
}

int	moves(t_stack *a, t_stack *b, int bond[2], int number)
{
	int	moves;
	int	moves_a;
	int	i;

	moves = number + 2;
	if (number > (b->top - 1) / 2)
		moves = b->top - number;
	i = pos_counter(a, b, number, bond);
	moves_a = i;
	if (i > a->top / 2)
		moves_a = a->top - i;
	if ((number > (b->top / 2) && i > (a->top / 2)) || \
	(number <= (b->top / 2) && i <= (a->top / 2)))
	{
		if (moves < moves_a)
			moves = moves_a;
	}
	else
		moves += moves_a;
	return (moves);
}

int	least_moves_number(t_stack *a, t_stack *b, int *group)
{
	int	i;
	int	boundaries[2];
	int	move;
	int	cmoves;
	int	index;

	boundaries[0] = find_smallest(a);
	boundaries[1] = find_biggest(a);
	i = b->top;
	while (i >= 0 && (b->array[i] > group[1] || b->array[i] < group[0]))
		i--;
	index = i;
	move = moves(a, b, boundaries, index);
	while (--i >= 0)
	{
		cmoves = moves(a, b, boundaries, i);
		if ((b->array[i] >= group[0] && b->array[i] <= group[1] && move \
		> cmoves) || (move == cmoves && b->array[index] < b->array[i]))
		{
			index = i;
			move = cmoves;
		}
	}
	return (index);
}

void	rr_stack(t_stack *a, t_stack *b, int number[2], int index[2])
{
	while (index[0] <= (b->top / 2) && b->array[b->top] != number[0] && \
	index[1] <= (a->top / 2) && a->array[0] != number[1])
		run(a, b, RRR);
	while (index[0] <= (b->top / 2) && b->array[b->top] != number[0])
		run(a, b, RRB);
	while (index[1] <= (a->top / 2) && a->array[0] != number[1])
		run(a, b, RRA);
}

void	r_stack(t_stack *a, t_stack *b, int number[2], int index[2])
{
	while (index[0] > (b->top / 2) && b->array[b->top] != number[0] \
	&& index[1] > (a->top / 2) && a->array[0] != number[1])
		run(a, b, RR);
	while (index[0] > (b->top / 2) && b->array[b->top] != number[0])
		run(a, b, RB);
	while (index[1] > (a->top / 2) && a->array[0] != number[1])
		run(a, b, RA);
}
