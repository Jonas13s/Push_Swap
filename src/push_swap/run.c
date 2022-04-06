/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:32:16 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 03:24:37 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("%s\n", str);
}

void	run_times(t_stack *a, t_stack *b, char *str, int times)
{
	while (times > 0)
	{
		run(a, b, str);
		times--;
	}
}
