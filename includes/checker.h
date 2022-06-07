/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:21:19 by joivanau          #+#    #+#             */
/*   Updated: 2022/06/07 16:25:51 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"
# include "libft.h"

int		read_line(t_stack *a, t_stack *b);
void	free_stack(t_stack *s, char *str);
int		free_stack_error(t_stack *a, t_stack *b, char *str);
char	**one_line(char **argv, int *count, int *mode);
int		free_stack_error_line(t_stack *a, t_stack *b, char **argv, int mode);
#endif