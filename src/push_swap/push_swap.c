/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:02 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/07 16:22:42 by joivanau         ###   ########.fr       */
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

static char	**one_line(char **argv, int *count, int *mode)
{
	int		i;
	int		k;
	char	**str;

	str = ft_strsplit(argv[1], ' ');
	i = 0;
	k = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ')
			k++;
		i++;
	}
	i = 0;
	while (str[i] != NULL)
		i++;
	*mode = 1;
	if (k + 1 > i)
		*mode = -1;
	*count = i + 1;
	return (str);
}

int	main(int args, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		mode[2];

	mode[1] = 0;
	mode[0] = 1;
	if (args != 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		mode[0] = 0;
		args--;
		argv++;
	}
	if (args == 2 && ft_strchr(argv[1], ' ') != 0)
		argv = one_line(argv, &args, &mode[1]);
	if (args == 1)
		return (0);
	a = initialize(args - 1, mode[0]);
	b = initialize(args - 1, mode[0]);
	if (check_number(argv, args, mode[1]) || mode[1] == -1)
		return (free_stack_error_line(a, b, argv, mode[1]));
	if (fill_stack(args, argv, a, mode[1]) == 1)
		return (free_stack(a, b, argv, mode[1]));
	solve(a, b, (args - 1));
	free_stack(a, b, argv, mode[1]);
	return (0);
}
