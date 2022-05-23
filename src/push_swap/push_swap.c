/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:02 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/23 15:28:31 by joivanau         ###   ########.fr       */
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

static void	print_debug(t_stack *a, t_stack *b)
{
	int	at;
	int	bt;

	at = a->top;
	bt = b->top;
	while (at >= 0 || bt >= 0)
	{
		ft_printf("║    ");
		if (at >= 0 && bt >= 0)
			ft_printf("%-11d  ║    %-11d  ║\n", a->array[at], b->array[bt]);
		else if (at >= 0 && bt < 0)
			ft_printf("%-11d  ║                 ║\n", a->array[at]);
		else if (bt >= 0 && at < 0)
			ft_printf("             ║    %-11d  ║\n", b->array[bt]);
		at--;
		bt--;
	}
}

int	debugging(t_stack *a, t_stack *b, char *str)
{
	usleep(200000);
	ft_printf("\033[2J");
	ft_printf("╔═══════════════════════════════════╗\n");
	ft_printf("║         stack operation: %-4s     ║\n", str);
	ft_printf("║═══════════════════════════════════║\n");
	ft_printf("║    stack :      ║    stack :      ║\n");
	ft_printf("║       A         ║       B         ║\n");
	print_debug(a, b);
	ft_printf("╚═══════════════════════════════════╝\n");
	return (1);
}

int	main(int args, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (args == 1)
		return (0);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		args--;
		argv++;
	}
	a = initialize(args - 1, ft_strcmp(argv[0], "-v"));
	b = initialize(args - 1, ft_strcmp(argv[0], "-v"));
	if (check_number(argv, args))
		return (free_stack_error(a, b, NULL));
	fill_stack(args, argv, a);
	if (check_order(a))
		return (free_stack(a, b));
	solve(a, b, (args - 1));
	free_stack(a, b);
	return (0);
}
