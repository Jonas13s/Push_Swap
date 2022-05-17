/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:02 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/17 13:54:26 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve(t_stack *a, t_stack *b, int count)
{
	if (count <= 5)
		solve_small(a, b);
	else
		solve_large(a, b);
	return (0);
}

int	main(int args, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = initialize(args - 1);
	b = initialize(args - 1);
	if (check_number(argv, args))
		return (free_stack_error(a, b, NULL));
	fill_stack(args, argv, a);
	if (check_order(a))
		return (free_stack(a, b));
	solve(a, b, (args - 1));
	free_stack(a, b);
}
