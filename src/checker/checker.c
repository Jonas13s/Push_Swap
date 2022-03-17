/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:23:41 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/17 01:52:11 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_number(char **str, int args)
{
	int	i;
	int	j;

	if (args <= 1)
		return (1);
	i = 1;
	while (str[i])
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
		i++;
	}
	return (0);
}

void	fill_stack(int args, char **argv, t_stack *stack)
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
