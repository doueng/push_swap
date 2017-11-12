/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:17:03 by douglas           #+#    #+#             */
/*   Updated: 2017/06/18 13:29:53 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		partition(int *tab, int low, int high)
{
	int pivot;
	int current;

	pivot = tab[high];
	current = low;
	while (current < high)
	{
		if (tab[current] <= pivot)
			ft_swap(&tab[low++], &tab[current], sizeof(int));
		current++;
	}
	ft_swap(&tab[low], &tab[high], sizeof(int));
	return (low);
}

void			ft_quicksort(int *tab, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(tab, low, high);
		ft_quicksort(tab, low, partition_index - 1);
		ft_quicksort(tab, partition_index + 1, high);
	}
}
