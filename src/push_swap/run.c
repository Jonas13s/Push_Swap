/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:32:16 by joivanau          #+#    #+#             */
/*   Updated: 2022/05/23 02:16:27 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_print(t_stack *a, t_stack *b, char *str)
{
	if (a->debug == 1)
		debugging(a, b, str);
	else
		ft_printf("%s\n", str);u
}

void	run(t_stack *a, t_stack *b, char *str)
{
	if (ft_strequ(SA, str))
		swap(a);
	else if (ft_strequ(SB, str))
		swap (b);
	else if (ft_strequ(SS, str))
		swap_both(a, b);
	else if (ft_strequ(PA, str))
		push_stack(b, a);
	else if (ft_strequ(PB, str))
		push_stack(a, b);
	else if (ft_strequ(RA, str))
		rotate(a);
	else if (ft_strequ(RB, str))
		rotate(b);
	else if (ft_strequ(RR, str))
		rotate_both(a, b);
	else if (ft_strequ(RRA, str))
		reverse_rotate(a);
	else if (ft_strequ(RRB, str))
		reverse_rotate(b);
	else if (ft_strequ(RRR, str))
		reverse_rotate_both(a, b);
	run_print(a, b, str);
}

void	run_times(t_stack *a, t_stack *b, char *str, int times)
{
	while (times > 0)
	{
		run(a, b, str);
		times--;
	}
}
