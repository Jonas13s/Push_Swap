/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:33:54 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/19 21:54:40 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_stack(t_stack *from, t_stack *to)
{
	if (from->top == -1)
		return ;
	to->top++;
	to->array[to->top] = from->array[from->top];
	from->top--;
}
