/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:44:19 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/08 11:52:07 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	free_argv(char **argv, int mode, int error)
{
	int	i;

	i = 0;
	if (mode == 1 || mode == -1)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
	return (1);
}
