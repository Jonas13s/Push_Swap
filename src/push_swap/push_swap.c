/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:02 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/29 13:27:14 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_stack *a)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		ft_printf("%d\n", a->array[a->top - i]);
		i++;
	}
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*correct_order(t_stack *a)
{
	int	i;
	int	*s;
	int	j;

	s = (int *)malloc(sizeof(int) * a->size + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (++i <= a->top)
		s[i] = a->array[i];
	i = -1;
	while (++i <= a->top - 1)
	{
		j = -1;
		while (++j <= a->top - 1)
		{
			if (s[j] < s[j + 1])
			{
				swap_int(&s[j], &s[j + 1]);
				i = 0;
			}
		}
	}
	return (s);
}

int	median(t_stack *a)
{
	int	ans;
	int	*num;

	num = correct_order(a);
	if (a->size % 2)
		ans = num[a->top / 2];
	else
		ans = (num[a->top / 2] + num[a->top / 2 + 1]) / 2;
	return (ans);
}

int	solve(t_stack *a, t_stack *b, int count)
{
	if (count <= 5)
		solve_small(a, b);
	(void)b;
	(void)count;
	(void)a;
	return (0);
}

int	main(int args, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (check_order(argv))
		return (1);
	a = initialize(args - 1);
	b = initialize(args - 1);
	if (check_number(argv, args))
		return (free_stack_error(a, b, NULL));
	fill_stack(args, argv, a);
	solve(a, b, (args - 1));
	print_array(a);
	free_stack(a, b);
	//print_array(a);
}
