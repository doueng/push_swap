/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:23:30 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 19:29:05 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		free_stack(t_stack *stack)
{
	t_num *node;
	t_num *tmp;

	node = stack->top;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}

void		free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
