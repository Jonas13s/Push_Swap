/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:11:51 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/15 15:55:06 by joivanau         ###   ########.fr       */
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
