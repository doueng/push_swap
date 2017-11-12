/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:03:43 by douglas           #+#    #+#             */
/*   Updated: 2017/06/16 20:20:25 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		*cpy_to_array(t_stack *stack, int len)
{
	int		*array;
	t_num	*current;
	int		i;

	if (!(array = (int*)malloc(sizeof(int) * len)))
		ft_error();
	current = stack->top;
	i = 0;
	while (len--)
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}
