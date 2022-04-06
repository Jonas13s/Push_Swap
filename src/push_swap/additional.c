/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:12:19 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 03:21:17 by joivanau         ###   ########.fr       */
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

int	free_stack(t_stack *a, t_stack *b)
{
	if (a->array)
		ft_memdel((void *)&a->array);
	if (a)
		ft_memdel((void *)&a);
	if (b->array)
		ft_memdel((void *)&b->array);
	if (b)
		ft_memdel((void *)&b);
	return (1);
}

size_t	chunk_counter(t_stack *a)
{
	size_t	count;

	count = (a->top + 1) / S_NUM + 1;
	return (count);
}

int	closest(t_stack *a, int num)
{
	int	k;
	int	i;

	if (a->top < 0 || num > find_biggest(a))
		return (num);
	i = 0;
	k = find_biggest(a);
	while (i <= a->top)
	{
		if (a->array[i] > num && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}
