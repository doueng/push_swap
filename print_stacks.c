/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:45:35 by douglas           #+#    #+#             */
/*   Updated: 2017/06/15 15:47:35 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		print_stacks(t_num *num_a, t_num *num_b, char *instruction,
						char *options)
{
	ft_printf("   %s\n", instruction);
	while (num_a || num_b)
	{
		if (options[1] == 'c' && num_a && num_a->color)
		{
			ft_printf("\x1B[31m%d\x1B[0m", num_a->value);
			num_a->color = 0;
			num_a = num_a->next;
		}
		else if (num_a && ft_printf("%d", num_a->value))
			num_a = num_a->next;
		ft_printf("\t");
		if (options[1] == 'c' && num_b && num_b->color)
		{
			ft_printf("\x1B[31m%d\x1B[0m", num_b->value);
			num_b->color = 0;
			num_b = num_b->next;
		}
		else if (num_b && ft_printf("%d", num_b->value))
			num_b = num_b->next;
		ft_printf("\n");
	}
	ft_printf("--	--\nA\tB\n");
	ft_printf("==========\n");
}
