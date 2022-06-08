/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:24:37 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/08 11:37:00 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	operations(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
		swap(a);
	else if (ft_strcmp(s, "sb") == 0)
		swap(b);
	else if (ft_strcmp(s, "ss") == 0)
		swap_both(a, b);
	else if (ft_strcmp(s, "pa") == 0)
		push_stack(b, a);
	else if (ft_strcmp(s, "pb") == 0)
		push_stack(a, b);
	else if (ft_strcmp(s, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(s, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(s, "rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(s, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(s, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(s, "rrr") == 0)
		reverse_rotate_both(a, b);
	else
		return (1);
	return (0);
}

static int	correct_order(t_stack *a, t_stack *b)
{
	int	i;

	if (b->top != -1 || a->top == -1)
		return (1);
	i = 1;
	while (i <= a->top)
	{
		if (a->array[i - 1] < a->array[i])
			return (1);
		i++;
	}
	return (0);
}

int	read_line(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			return (free_stack_error(a, b, NULL));
		if (operations(line, a, b))
		{
			ft_strdel(&line);
			return (free_stack_error(a, b, NULL));
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (correct_order(a, b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}

int	free_argv(char **argv, int mode, int error)
{
	int	i;

	i = 0;
	if (mode == 1 || mode == -1)
	{
		while (argv[i])
		{
			ft_memdel((void *) &argv[i]);
			i++;
		}
		ft_memdel((void **) &argv);
	}
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
	return (1);
}
