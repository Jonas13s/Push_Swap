/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:57:59 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/23 00:48:34 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	unsigned int	size;
	int				top;
	int				*array;
	int				debug;
}					t_stack;

void		swap(t_stack *s);
t_stack		*initialize(unsigned int size, int debug);
void		reverse_rotate(t_stack *s);
void		rotate(t_stack *s);
void		push_stack(t_stack *from, t_stack *to);
void		swap_both(t_stack *a, t_stack *b);
void		rotate_both(t_stack *a, t_stack *b);
void		reverse_rotate_both(t_stack *a, t_stack *b);
#endif