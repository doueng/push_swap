/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:26:26 by douglas           #+#    #+#             */
/*   Updated: 2017/07/06 22:37:07 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	check_duplicates(t_stack *stack)
{
	t_num	*num;
	t_num	*tmp;

	num = stack->top;
	while (num->next)
	{
		tmp = num->next;
		while (tmp)
		{
			if (num->value == tmp->value)
				ft_error();
			tmp = tmp->next;
		}
		num = num->next;
	}
}

int		is_sorted(t_num *num)
{
	while (num->next)
	{
		if (num->value > num->next->value)
			return (0);
		num = num->next;
	}
	return (1);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}
