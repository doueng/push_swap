/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:01:34 by douglas           #+#    #+#             */
/*   Updated: 2017/07/17 16:28:24 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft/libft.h"
# define RED  "\x1B[31m"
# define NRM  "\x1B[0m"

typedef struct		s_lst
{
	int				value;
	int				color;
	int				group;
	struct s_lst	*next;
}					t_num;

typedef	struct		s_stack
{
	t_num			*top;
	t_num			*bottom;
	int				len;
	char			name;
}					t_stack;

void				add_color(t_num **num_a, t_num **num_b, char **instruction);
void				ft_error(void);
void				print_stacks(t_num *num_a, t_num *num_b,
									char *instruction, char *options);
void				do_instruction(t_stack *stack_a, t_stack *stack_b,
									char *instruction, char *options);
void				add_to_stack(char *argv, t_stack *stack);
t_stack				*create_stack(void);
void				swap(t_stack *stack, char *print);
void				push(t_stack *src, t_stack *dst, char *print);
void				rotate(t_stack *stack, char *print);
void				rrotate(t_stack *stack, char *print);
void				selection_sort(t_stack *stack_a, t_stack *stack_b);
int					*cpy_to_array(t_stack *stack, int len);
void				quicksort_stacks(t_stack *src, t_stack *dst);
void				check_duplicates(t_stack *stack);
int					is_sorted(t_num *top);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
