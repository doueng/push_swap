/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:13:55 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/20 14:00:51 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	get_group_len(t_stack *stack)
{
	t_num	*tmp;
	int		count;
	int		group;

	group = stack->top->group;
	tmp = stack->top;
	count = 0;
	while (tmp && tmp->group == group)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static int	find_median(t_stack *stack, int group_len)
{
	int		*array;
	int		median;

	array = cpy_to_array(stack, group_len);
	ft_quicksort(array, 0, group_len - 1);
	median = array[(group_len / 2)];
	free(array);
	return (median);
}

static int	partition(t_stack *src, t_stack *dst)
{
	int		pivot;
	int		rotated;
	int		group_len;

	group_len = get_group_len(src);
	rotated = 0;
	pivot = find_median(src, group_len);
	while (group_len--)
	{
		if (src->name == 'a' && src->top->value < pivot)
			push(src, dst, "pb");
		else if (src->name == 'b' && src->top->value >= pivot)
			push(src, dst, "pa");
		else
		{
			rotated++;
			rotate(src, "ra || rb");
		}
	}
	return (rotated);
}

static void	less_than_two_sort(t_stack *src, t_stack *dst)
{
	int group_len;

	group_len = get_group_len(src);
	if (group_len == 2)
	{
		if (src->name == 'a' && src->top->value > src->top->next->value)
			swap(src, "sa");
		if (src->name == 'b' && src->top->value < src->top->next->value)
			swap(src, "sb");
	}
	while (src->name == 'b' && group_len--)
		push(src, dst, "pa");
}

void		quicksort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	needs_rrotate;
	int	rotated_down;

	while (1)
	{
		while (2 < get_group_len(stack_a))
		{
			rotated_down = partition(stack_a, stack_b);
			needs_rrotate = stack_a->len > get_group_len(stack_a);
			while (needs_rrotate && rotated_down--)
				rrotate(stack_a, "rra");
		}
		if (2 >= get_group_len(stack_a))
			less_than_two_sort(stack_a, stack_b);
		if (2 >= get_group_len(stack_b))
			less_than_two_sort(stack_b, stack_a);
		if (!stack_b->top)
			return ;
		rotated_down = partition(stack_b, stack_a);
		needs_rrotate = stack_b->len > get_group_len(stack_b);
		while (needs_rrotate && rotated_down--)
			rrotate(stack_b, "rrb");
	}
}
