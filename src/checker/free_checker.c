/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:33:07 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/06 12:15:45 by joivanau         ###   ########.fr       */
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

char	**one_line(char **argv, int *count, int *mode)
{
	int		i;
	char	**str;

	str = ft_strsplit(argv[1], ' ');
	i = 0;
	while (str[i] != NULL)
		i++;
	*count = i + 1;
	*mode = 1;
	return (str);
}
