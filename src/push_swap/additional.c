/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:12:19 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/05 18:53:22 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	free_stack_error(t_stack *a, t_stack *b, char *str)
{
	if (a->array)
		ft_memdel((void *)&a->array);
	if (a)
		ft_memdel((void *)&a);
	if (b->array)
		ft_memdel((void *)&b->array);
	if (b)
		ft_memdel((void *)&b);
	if (str)
		ft_strdel(&str);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	free_stack(t_stack *a, t_stack *b, char **argv, int mode)
{
	int	i;

	i = 0;
	if (a->array)
		ft_memdel((void *)&a->array);
	if (a)
		ft_memdel((void *)&a);
	if (b->array)
		ft_memdel((void *)&b->array);
	if (b)
		ft_memdel((void *)&b);
	if (mode == 1)
	{
		while (argv[i])
		{
			ft_memdel((void *) &argv[i]);
			i++;
		}
		ft_memdel((void **) &argv);
	}
	return (1);
}

int	find_biggest(t_stack *s)
{
	int	biggest;
	int	i;

	i = s->top;
	biggest = s->array[s->top];
	while (i >= 0)
	{
		if (s->array[i] > biggest)
			biggest = s->array[i];
		i--;
	}
	return (biggest);
}

int	find_smallest(t_stack *s)
{
	int	smallest;
	int	i;

	i = s->top;
	smallest = s->array[s->top];
	while (i >= 0)
	{
		if (s->array[i] < smallest)
			smallest = s->array[i];
		i--;
	}
	return (smallest);
}
