/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:54:42 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/01 01:54:58 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_below(t_stack *a, t_stack *b, int med)
{
	int	i;
	int	o;
	int	k;

	k = a->top / 2;
	while(k != a->top)
	{
		o = a->top + 1;
		i = -1;
		while(++i <= a->top)
		{
			if (a->array[i] <= med)
				break ;
		}
		while (--o != -1)
		{
			if (a->array[o] <= med)
				break ;
		}
		if ((a->top - o) >= i + 1)
			best_move(a, 'a', a->array[i]);
		else
			best_move(a, 'a', a->array[o]);
		run(a, b, PB);
	}
}

void	push_above(t_stack *a, t_stack *b, int med)
{
	int	i;
	int	o;
	int	k;

	k = a->top / 2;
	while(k != a->top)
	{
		o = a->top + 1;
		i = -1;
		while(++i <= a->top)
		{
			if (a->array[i] > med)
				break ;
		}
		while (--o != -1)
		{
			if (a->array[o] > med)
				break ;
		}
		if ((a->top - o) >= i + 1)
			best_move(a, 'a', a->array[i]);
		else
			best_move(a, 'a', a->array[o]);
		run(a, b, PB);
	}
}


void	push_back(t_stack *a, t_stack *b)
{
	int	k;
	int	count;

	count = 0;
	while (b->top != -1)
	{
		k = best_pos(b, find_smallest(b), find_biggest(b));
		run(a, b, PA);
		if (k == 1)
			run(a, b, RA);
		else
			count++;
	}
	while(count != 0)
	{
		run(a, b, RA);
		count--;
	}
}
