/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:48 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/28 17:35:43 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move_top(t_stack *s, int num)
{
	int	i;

	i = -1;
	while (++i <= s->top)
	{
		if (s->array[s->top - i] == num)
			return (i);
	}
	return (-1);
}

int	best_move_bottom(t_stack *s, int num)
{
	int	i;

	i = -1;
	while (++i <= s->top)
	{
		if (s->array[i] == num)
			return (i);
	}
	return (-1);
}

int	best_move(t_stack *s, char c)
{
	int	small;
	int	moves[2];

	small = find_smallest(s);
	moves[0] = best_move_bottom(s, small);
	moves[1] = best_move_top(s, small);
	if (moves[1] == 0)
		return (1);
	if (c == 'a')
	{
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
	}
	return (1);
}
