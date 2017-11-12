/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:23:52 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 19:17:53 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack			*create_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		ft_error();
	stack->top = NULL;
	stack->bottom = NULL;
	stack->len = 0;
	return (stack);
}

static int		get_len(char **split)
{
	int count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void			add_to_stack(char *nums, t_stack *stack)
{
	t_num	*num;
	char	**split;
	int		i;

	split = ft_strsplit(nums, ' ');
	i = get_len(split);
	num = NULL;
	while (i--)
	{
		if (!ft_is_int(split[i]) || !(num = (t_num*)malloc(sizeof(t_num))))
			ft_error();
		num->value = ft_atoi(split[i]);
		num->color = 0;
		num->group = 0;
		if (!stack->bottom)
		{
			num->next = NULL;
			stack->bottom = num;
		}
		else
			num->next = stack->top;
		stack->top = num;
		stack->len++;
	}
	ft_free_split(split);
}
