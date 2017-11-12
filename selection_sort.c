/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:04:53 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 19:13:46 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int		num_in_bottom_half(t_stack *stack, int num)
{
	int		i;
	t_num	*num_lst;

	num_lst = stack->top;
	i = stack->len / 2 + 1;
	while (i--)
		num_lst = num_lst->next;
	while (num_lst)
	{
		if (num_lst->value == num)
			return (1);
		num_lst = num_lst->next;
	}
	return (0);
}

static int		find_smallest(t_stack *stack_a)
{
	t_num	*num;
	int		smallest;

	num = stack_a->top;
	smallest = num->value;
	while (num)
	{
		if (num->value < smallest)
			smallest = num->value;
		num = num->next;
	}
	return (smallest);
}

static void		three_sort(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->bottom->value)
		rotate(stack_a, "ra");
	if (stack_a->top->value > stack_a->top->next->value)
		swap(stack_a, "sa");
	if (stack_a->top->next->value > stack_a->bottom->value)
	{
		rrotate(stack_a, "rra");
		swap(stack_a, "sa");
	}
}

void			selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	bottom_half;
	int	smallest;
	int	pushed;

	i = 0;
	pushed = 0;
	while (stack_a->len > 3)
	{
		smallest = find_smallest(stack_a);
		bottom_half = num_in_bottom_half(stack_a, smallest);
		while (stack_a->top->value != smallest)
		{
			if (bottom_half)
				rrotate(stack_a, "rra");
			else
				rotate(stack_a, "ra");
		}
		i++;
		push(stack_a, stack_b, "pb");
		pushed++;
	}
	three_sort(stack_a);
	while (pushed--)
		push(stack_b, stack_a, "pa");
}
