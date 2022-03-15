/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:26:28 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/16 00:26:36 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:34:15 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/15 15:55:47 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *s)
{
	unsigned int	i;
	int				temp;

	temp = s->array[s->top];
	i = s->top + 1;
	while (--i)
		s->array[i] = s->array[i - 1];
	s->array[0] = temp;
}

void	reverse_rotate(t_stack *s)
{
	int	i;
	int	temp;

	temp = s->array[0];
	i = -1;
	while (++i < s->top)
		s->array[i] = s->array[i + 1];
	s->array[s->top] = temp;
}
