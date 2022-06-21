/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:28:05 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/19 21:32:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*initialize(unsigned int size, int debug)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * (size + 1));
	if (!stack->array)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	if (debug == 0)
		stack->debug = 1;
	else
		stack->debug = 0;
	return (stack);
}
