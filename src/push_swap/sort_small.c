/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:25:52 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/23 01:04:33 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_small(t_stack *a, t_stack *b)
{
	int	*arr;

	arr = a->array;
	if (arr[2] > arr[1] && arr[2] < arr[0])
		run(a, b, "sa");
	if (arr[2] > arr[1] && arr[1] > arr[0])
	{
		run(a, b, "sa");
		run(a, b, "rra");
	}
	if (arr[2] > arr[0] && arr[1] < arr[0] && arr[1] < arr[2])
		run(a, b, "ra");
	if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] < arr[0])
	{
		run(a, b, "sa");
		run(a, b, "ra");
	}
	if (arr[2] < arr[1] && arr[1] > arr[0])
		run(a, b, "rra");
	return (1);
}

static void	get_top(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = a->top;
	while (a->array[i] != number)
		i--;
	if (i > a->top / 2)
		while (a->array[a->top] != number)
			run(a, b, RA);
	else
		while (a->array[a->top] != number)
			run(a, b, RRA);
}

int	solve_small(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run(a, b, SA);
	if (a->top == 2)
		check_small(a, b);
	if (a->top == 3)
	{
		get_top(a, b, find_smallest(a));
		run(a, b, PB);
		check_small(a, b);
		run(a, b, PA);
	}
	if (a->top == 4)
	{
		get_top(a, b, find_smallest(a));
		run(a, b, PB);
		get_top(a, b, find_smallest(a));
		run(a, b, PB);
		check_small(a, b);
		run(a, b, PA);
		run(a, b, PA);
	}
	return (0);
}
