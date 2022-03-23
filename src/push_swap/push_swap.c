/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:02 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/22 20:28:04 by joivanau         ###   ########.fr       */
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

int	get_top(t_stack *a, int num);

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

int	push_med(t_stack *a, t_stack *b, int med)
{
	int	min;
	int	max;
	int	i;
	(void)b;

	max = -1;
	min = -1;
	i = a->top;
	while(a->array[i])
	{
		if (a->array[i] <= med)
		{
			min = i;
			break ;
		}
		i--;
	}
	i = 0;
	while(a->array[i] && i < a->top)
	{
		if (a->array[i] <= med)
		{
			max = i;
			break ;
		}
		i++;
	}
	if (min == -1 || max == -1)
		return (1);
	if (a->top - min < max)
		i = a->array[min];
	else
		i = a->array[max];
	get_top(a, i);
	push_stack(a, b);
	//print_array(a);
	return (0);
}	

int	solve(t_stack *a, t_stack *b, int count)
{
	int	med;
	(void)b;
	(void)count;
	med = median(a);
	push_med(a, b, med);
	push_med(a, b, med);
	push_med(a, b, med);
	push_med(a, b, med);
	push_med(a, b, med);
	print_array(a);
	//ft_printf("%d\n", med);
	return (0);
}

int	get_top(t_stack *a, int num)
{
	int	count;
	int	i;

	while (a->array[a->top] != num)
	{
		i = a->top;
		count = 0;
		while (a->array[i] != num)
			i--;
		if (a->top - 1 == -1 || a->array[a->top] == num)
			return (1);
		if (a->top - i <= a->top / 2)
		{
			ft_printf("ra\n");
			rotate(a);
		}
		else
		{
			ft_printf("rra\n");
			reverse_rotate(a);
		}
	}
	//ft_printf("number: %d, count %d\n", num, a.top - i);
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
	solve(a, b, (args - 2));
	//print_array(a);
}
