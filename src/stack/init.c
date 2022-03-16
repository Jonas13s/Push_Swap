/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:28:05 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/16 02:00:57 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*initialize(unsigned int size)
{
	t_stack *stack;

	stack = malloc(sizeof(stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * (size + 1));
	if (!stack->array)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}
