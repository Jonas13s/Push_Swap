/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:57:59 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/16 00:42:19 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

typedef struct s_stack
{
	unsigned int	size;
	int				top;
	int				*array;
}					t_stack;

void		swap(t_stack *s);
t_stack		*initialize(unsigned int size);
void		reverse_rotate(t_stack *s);
void		rotate(t_stack *s);
void		push_stack(t_stack *from, t_stack *to);

#endif