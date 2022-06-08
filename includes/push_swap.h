/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:04:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/08 11:35:13 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

# define S_NUM 75

/* debug.cc */
int		debugging(t_stack *a, t_stack *b, char *str);
int		free_argv(char **argv, int mode, int error);
/*check.c*/
int		check_number(char **str, int args, int mode);
int		free_stack_error_line(t_stack *a, t_stack *b, char **argv, int mode);
int		check_order(t_stack *a);
/* run.c */
void	run(t_stack *a, t_stack *b, char *str);
void	run_times(t_stack *a, t_stack *b, char *str, int times);
/*solve_small.c*/
int		solve_small(t_stack *a, t_stack *b);
/*solve_large.c*/
int		solve_large(t_stack *a, t_stack *b);
/*additional.c*/
int		free_stack(t_stack *a, t_stack *b, char **argv, int mode);
int		fill_stack(int args, char **argv, t_stack *stack, int mode);
int		free_stack_error(t_stack *a, t_stack *b, char *str);
int		find_smallest(t_stack *s);
int		find_biggest(t_stack *s);
/*groups.c*/
int		**int_groups(t_stack *s, int num);
void	push_group(t_stack *a, t_stack *b, int *group);
int		has_group(t_stack *s, int *group);
/*moves.c*/
void	push_group_back(t_stack *a, t_stack *b, int *group);
void	r_stack(t_stack *a, t_stack *b, int number[2], int index[2]);
void	rr_stack(t_stack *a, t_stack *b, int number[2], int index[2]);
int		least_moves_number(t_stack *a, t_stack *b, int *group);
int		moves(t_stack *a, t_stack *b, int bond[2], int number);
#endif