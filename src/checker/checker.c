/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:23:41 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/25 13:09:19 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	dup_check(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[++j])
		{
			if (i == j)
				continue ;
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
		}
	}
	return (0);
}

static int	check_size(char *str)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (str[++i])
	{
		if (str[i] == '-' && i == 0)
			continue ;
		size += str[i];
	}
	if (str[0] == '-' && size <= 527)
		return (0);
	if (size <= 526)
		return (0);
	return (1);
}

static int	check_number(char **str, int args)
{
	int		i;
	int		j;

	if (args <= 1)
		return (1);
	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		if (check_size(str[i]))
			return (1);
	}
	if (dup_check(str))
		return (1);
	return (0);
}

static void	fill_stack(int args, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	args = args - 2;
	stack->top = args;
	while (args != -1)
	{
		stack->array[args] = ft_atoi(argv[i]);
		args--;
		i++;
	}
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
	if (read_line(a, b))
		return (1);
	free_stack(a, NULL);
	free_stack(b, NULL);
	return (0);
}
