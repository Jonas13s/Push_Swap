/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:04:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/18 02:16:14 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

int		free_stack_error(t_stack *a, t_stack *b, char *str);
void	fill_stack(int args, char **argv, t_stack *stack);
int		check_number(char **str, int args);
#endif