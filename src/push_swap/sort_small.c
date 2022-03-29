/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:25:52 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/28 17:29:34 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_small(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[2] > arr[1] && arr[2] < arr[0])
		run(a, NULL, "sa");
	if (arr[2] > arr[1] && arr[1] > arr[0])
	{
		run(a, NULL, "sa");
		run(a, NULL, "rra");
	}
	if (arr[2] > arr[0] && arr[1] < arr[0] && arr[1] < arr[2])
		run(a, NULL, "ra");
	if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] < arr[0])
	{
		run(a, NULL, "sa");
		run(a, NULL, "ra");
	}
	if (arr[2] < arr[1] && arr[1] > arr[0])
		run(a, NULL, "rra");
	return (1);
}

int	solve_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		run(a, b, SA);
	if (a->size == 3)
		check_small(a);
	if (a->size == 4)
	{
		get_top(a, find_smallest(a));
		run(a, b, PB);
		check_small(a);
		run(a, b, PA);
	}
	if (a->size == 5)
	{
		get_top(a, find_smallest(a));
		run(a, b, PB);
		get_top(a, find_smallest(a));
		run(a, b, PB);
		check_small(a);
		run(a, b, PA);
		run(a, b, PA);
	}
	return (0);
}
