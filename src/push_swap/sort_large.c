/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:17 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/23 01:30:54 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_group_back(t_stack *a, t_stack *b, int *group)
{
	int	index[2];
	int	number[2];
	int	biggest;
	int	smallest;

	while (has_group(b, group))
	{
		smallest = find_smallest(a);
		biggest = find_biggest(a);
		index[0] = least_moves_number(a, b, group);
		number[0] = b->array[index[0]];
		index[1] = a->top;
		while (number[0] > smallest && number[0] < biggest && index[1] > 0 && \
		(number[0] < a->array[index[1]] || number[0] > a->array[index[1] - 1]))
			index[1]--;
		while ((number[0] < smallest || number[0] > biggest) && index[1] >= 0 \
		&& a->array[index[1]] != biggest)
			index[1]--;
		number[1] = a->array[index[1]];
		r_stack(a, b, number, index);
		rr_stack(a, b, number, index);
		run(a, b, PA);
	}
}

static void	rotate_smallest(t_stack *a, t_stack *b)
{
	int	smallest;
	int	i;

	smallest = find_smallest(a);
	i = a->top;
	while (a->array[i] != smallest)
		i--;
	if (i > a->top / 2)
		while (a->array[a->top] != smallest)
			run(a, b, RA);
	else
		while (a->array[a->top] != smallest)
			run(a, b, RRA);
}

int	solve_large(t_stack *a, t_stack *b)
{
	int	**groups;
	int	num;
	int	i;

	if (a->top < 70)
		num = 1;
	else if (a->top < 100)
		num = 2;
	else
		num = 4;
	groups = int_groups(a, num);
	i = 1;
	while (i <= groups[0][0])
		push_group(a, b, groups[i++]);
	i = groups[0][0];
	while (i > 0)
	{
		push_group_back(a, b, groups[i]);
		free(groups[i]);
		i--;
	}
	free(groups[0]);
	free(groups);
	rotate_smallest(a, b);
	return (0);
}
