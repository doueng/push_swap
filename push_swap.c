/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:06:51 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 19:20:19 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static char	*get_numbers(int argc, char *argv[])
{
	int		i;
	char	*nums;

	nums = NULL;
	i = 0;
	while (--argc > 0)
	{
		if (!(nums = ft_strjoinfree(1, nums, 0, argv[++i])))
			ft_error();
		if (!(nums = ft_strjoinfree(1, nums, 0, " ")))
			ft_error();
	}
	return (nums);
}

int			main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	*nums;

	if (argc < 2)
		return (0);
	nums = get_numbers(argc, argv);
	stack_a = create_stack();
	stack_a->name = 'a';
	stack_b = create_stack();
	stack_b->name = 'b';
	(ft_strlen(nums)) ?
		add_to_stack(nums, stack_a) : add_to_stack(*++argv, stack_a);
	free(nums);
	check_duplicates(stack_a);
	if (is_sorted(stack_a->top))
		return (0);
	if (stack_a->len < 20)
		selection_sort(stack_a, stack_b);
	else
		quicksort_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
