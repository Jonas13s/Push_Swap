/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:33:07 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/17 02:08:34 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *s, char *str)
{
	if (s->array)
		ft_memdel((void *)&s->array);
	if (s)
		ft_memdel((void *)&s);
	if (str)
		ft_strdel(&str);
}

int	free_stack_error(t_stack *a, t_stack *b, char *str)
{
	if (a->array)
		ft_memdel((void *)&a->array);
	if (a)
		ft_memdel((void *)&a);
	if (b->array)
		ft_memdel((void *)&b->array);
	if (b)
		ft_memdel((void *)&b);
	if (str)
		ft_strdel(&str);
	ft_putstr_fd("Error\n", 2);
	return (1);
}
