/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:21:19 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/18 02:14:21 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"
# include "libft.h"

int		read_line(t_stack *a, t_stack *b);
void	free_stack(t_stack *s, char *str);
int		free_stack_error(t_stack *a, t_stack *b, char *str);
#endif