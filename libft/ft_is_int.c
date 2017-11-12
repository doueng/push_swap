/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:57:27 by douglas           #+#    #+#             */
/*   Updated: 2017/07/14 18:32:36 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *str)
{
	if (ft_strcmp(str, "-2147483648") == 0)
		return (1);
	if (*str == '-')
		str++;
	if (ft_strlen(str) > ft_strlen("2147483647"))
		return (0);
	if (ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}
