/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:04:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/04/06 03:22:16 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"
# include <stdio.h>

# define S_NUM 75

int		free_stack_error(t_stack *a, t_stack *b, char *str);
int		free_stack(t_stack *a, t_stack *b);
void	fill_stack(int args, char **argv, t_stack *stack);
int		check_number(char **str, int args);
int		check_order(char **argv);
int		*correct_order(t_stack *a);
int		median(t_stack *a);
/* move_chunk.c*/
void	move_chunk(t_stack *a, t_stack *b, int min, int max);
void	get_top_a(t_stack *a, int num);
/* best_move.c*/
int		best_move_bottom(t_stack *s, int num);
int		best_move(t_stack *s, char c, int small);
int		best_move_top(t_stack *s, int num);
/*additional_check.c */
int		find_biggest(t_stack *s);
int		find_smallest(t_stack *s);
int		get_top(t_stack *s, int num);
/*additional.c*/
size_t	chunk_counter(t_stack *a);
int		closest(t_stack *a, int num);
/* run.c */
void	run(t_stack *a, t_stack *b, char *str);
void	run_times(t_stack *a, t_stack *b, char *str, int times);
/*solve_small.c*/
int		solve_small(t_stack *a, t_stack *b);
/*solve_large.c*/
int		solve_median(t_stack *a, t_stack *b);
int		solve_large(t_stack *a, t_stack *b);
/*solve_median.c*/
int		best_pos(t_stack *s, int small, int big);
void	push_back(t_stack *a, t_stack *b);
#endif