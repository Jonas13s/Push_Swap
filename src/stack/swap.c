/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:27:00 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/25 13:30:55 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *s)
{
	int	temp;

	if (s->top <= 0)
		return ;
	temp = s->array[s->top];
	s->array[s->top] = s->array[s->top - 1];
	s->array[s->top - 1] = temp;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
