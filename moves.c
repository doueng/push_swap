/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:44:32 by douglas           #+#    #+#             */
/*   Updated: 2017/07/20 13:34:48 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_stack *stack, char *print)
{
	t_num *node;

	if (stack->len < 2)
		return ;
	if (print)
	{
		ft_putchar('s');
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	node = stack->top;
	stack->top = node->next;
	node->next = stack->top->next;
	stack->top->next = node;
	stack->top->color = 1;
	stack->top->next->color = 1;
	stack->top->group++;
	stack->top->next->group++;
	if (stack->len == 2)
		stack->bottom = stack->top->next;
}

void	push(t_stack *src, t_stack *dst, char *print)
{
	t_num *tmp;

	if (src->len < 1)
		return ;
	if (print)
	{
		ft_putchar('p');
		ft_putchar(dst->name);
		ft_putchar('\n');
	}
	tmp = src->top->next;
	src->top->next = dst->top;
	dst->top = src->top;
	if (!dst->bottom)
		dst->bottom = dst->top;
	src->top = tmp;
	src->len--;
	dst->len++;
	dst->top->color = 1;
	dst->top->group++;
}

void	rotate(t_stack *stack, char *print)
{
	if (stack->len < 2)
		return ;
	if (print)
	{
		ft_putchar('r');
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = NULL;
	stack->bottom->color = 1;
	stack->bottom->group++;
}

void	rrotate(t_stack *stack, char *print)
{
	t_num *tmp;

	if (stack->len < 2)
		return ;
	if (print)
	{
		ft_putstr("rr");
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	stack->top->color = 1;
}
