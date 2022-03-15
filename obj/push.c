/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:04 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/15 15:48:42 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_stack(t_stack *a, t_stack *b, int option)
{
	if (option == 'a')
	{
		if (b->top <= 0)
			return ;
		a->top++;
		a->array[a->top] = b->array[b->top];
		b->top--;
	}
	if (option == 'b')
	{
		if (a->top <= 0)
			return ;
		b->top++;
		b->array[b->top] = a->array[a->top];
		a->top--;
	}
	else
		return ;
}
