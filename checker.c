/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:02:56 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 16:31:07 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void		check_sorted(t_num *top, t_stack *stack_b)
{
	if (stack_b->top)
		return (ft_putendl("KO"));
	if (is_sorted(top))
		return (ft_putendl("OK"));
	ft_putendl("KO");
}

static void		add_option(char options[], char o)
{
	if (o == 'v')
		options[0] = 'v';
	else if (o == 'c')
		options[1] = 'c';
	else
		ft_error();
}

static char		*get_options(int argc, char *argv[], char **nums)
{
	char	*options;
	int		i;
	int		ii;

	if (argc < 2 || !(options = ft_strnew(3)))
		exit(0);
	ii = 1;
	while (--argc)
	{
		i = 1;
		if (argv[argc][0] == '-')
			while (argv[argc][i])
				add_option(options, argv[argc][i++]);
		else
		{
			if (!(*nums = ft_strjoinfree(1, *nums, 0, argv[ii++])))
				ft_error();
			if (!(*nums = ft_strjoinfree(1, *nums, 0, " ")))
				ft_error();
		}
	}
	return (options);
}

int				main(int argc, char *argv[])
{
	char	*instruction;
	t_stack *stack_a;
	t_stack *stack_b;
	char	*options;
	char	*nums;

	nums = NULL;
	options = get_options(argc, argv, &nums);
	stack_a = create_stack();
	stack_b = create_stack();
	(ft_strlen(nums)) ?
		add_to_stack(nums, stack_a) : add_to_stack(argv[1], stack_a);
	free(nums);
	check_duplicates(stack_a);
	if (options[0] == 'v')
		print_stacks(stack_a->top, stack_b->top, "START", options);
	while (0 < get_next_line(0, &instruction))
		do_instruction(stack_a, stack_b, instruction, options);
	free(instruction);
	check_sorted(stack_a->top, stack_b);
	free(options);
	free_stacks(stack_a, stack_b);
	return (0);
}
