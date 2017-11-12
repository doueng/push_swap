/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:29:37 by douglas           #+#    #+#             */
/*   Updated: 2017/06/28 21:18:50 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	rotate_instruction(t_stack *stack_a, t_stack *stack_b,
							char *instruction)
{
	if (ft_strequ(instruction, "ra"))
		rotate(stack_a, NULL);
	else if (ft_strequ(instruction, "rb"))
		rotate(stack_b, NULL);
	else if (ft_strequ(instruction, "rr"))
	{
		rotate(stack_b, NULL);
		rotate(stack_a, NULL);
	}
	else if (ft_strequ(instruction, "rra"))
		rrotate(stack_a, NULL);
	else if (ft_strequ(instruction, "rrb"))
		rrotate(stack_b, NULL);
	else if (ft_strequ(instruction, "rrr"))
	{
		rrotate(stack_a, NULL);
		rrotate(stack_b, NULL);
	}
	else
		ft_error();
}

void		do_instruction(t_stack *stack_a, t_stack *stack_b,
						char *instruction, char *options)
{
	if (!instruction)
		ft_error();
	if (ft_strequ(instruction, "sa"))
		swap(stack_a, NULL);
	else if (ft_strequ(instruction, "sb"))
		swap(stack_b, NULL);
	else if (ft_strequ(instruction, "ss"))
	{
		swap(stack_a, NULL);
		swap(stack_b, NULL);
	}
	else if (ft_strequ(instruction, "pa"))
		push(stack_b, stack_a, NULL);
	else if (ft_strequ(instruction, "pb"))
		push(stack_a, stack_b, NULL);
	else if (instruction[0] == 'r')
		rotate_instruction(stack_a, stack_b, instruction);
	else
		ft_error();
	if (options[0] == 'v')
		print_stacks(stack_a->top, stack_b->top, instruction, options);
	free(instruction);
}
