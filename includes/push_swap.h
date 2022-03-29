/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:04:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/29 16:18:03 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

int		free_stack_error(t_stack *a, t_stack *b, char *str);
int		free_stack(t_stack *a, t_stack *b);
void	fill_stack(int args, char **argv, t_stack *stack);
int		check_number(char **str, int args);
int		check_order(char **argv);
int		median(t_stack *a);
/* best_move.c*/
int		best_move_bottom(t_stack *s, int num);
int		best_move(t_stack *s, char c, int small);
int		best_move_top(t_stack *s, int num);
/*additional_check.c */
int		find_biggest(t_stack *s);
int		find_smallest(t_stack *s);
int		get_top(t_stack *s, int num);
/* run.c */
void	run(t_stack *a, t_stack *b, char *str);
/*solve_small.c*/
int		solve_small(t_stack *a, t_stack *b);
/*solve_large.c*/
int		solve_large(t_stack *a, t_stack *b);
#endif