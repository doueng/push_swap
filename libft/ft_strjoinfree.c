/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:57:22 by douglas           #+#    #+#             */
/*   Updated: 2017/06/25 14:17:12 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(int free1, char *s1, int free2, char *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	ii;

	joined = (char*)ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!joined)
		return (NULL);
	i = 0;
	ii = 0;
	while (s1 && s1[ii])
		joined[i++] = s1[ii++];
	ii = 0;
	while (s2 && s2[ii])
		joined[i++] = s2[ii++];
	joined[i] = '\0';
	if (free1 && s1)
		free(s1);
	if (free2 && s2)
		free(s2);
	return (joined);
}
