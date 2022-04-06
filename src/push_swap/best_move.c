/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:48 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 15:36:24 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move_top(t_stack *s, int num)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{
		if (s->array[i] == num)
			return (s->top - i);
		i--;
	}
	return (-1);
}

int	best_move_bottom(t_stack *s, int num)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->array[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	best_move_a(t_stack *s, int small)
{
	int	moves[2];

	moves[0] = -1;
	moves[1] = -1;
	moves[0] = best_move_bottom(s, small);
	moves[1] = best_move_top(s, small);
	if (moves[1] == -1 && moves[0] == -1)
		return (0);
	if (moves[1] == 0)
		return (1);
	if (moves[0] == 0)
		run(s, NULL, RRA);
	else if (moves[0] >= moves[1])
		while (--moves[1] != -1)
			run(s, NULL, RA);
	else
	{
		while (moves[0] != -1)
		{
			run(s, NULL, RRA);
			--moves[0];
		}
	}
	return (1);
}

int	best_move_b(t_stack *s, int small)
{
	int	moves[2];

	moves[0] = -1;
	moves[1] = -1;
	moves[0] = best_move_bottom(s, small);
	moves[1] = best_move_top(s, small);
	if (moves[1] == -1 && moves[0] == -1)
		return (0);
	if (moves[1] == 0)
		return (1);
	if (moves[0] == 0)
		run(NULL, s, RRB);
	else if (moves[0] >= moves[1])
		while (--moves[1] != -1)
			run(NULL, s, RB);
	else
	{
		while (moves[0] != -1)
		{
			run(NULL, s, RRB);
			--moves[0];
		}
	}
	return (1);
}
