/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:18:58 by asabri            #+#    #+#             */
/*   Updated: 2023/03/15 14:24:30 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		p = malloc(sizeof(char) * 1);
		if (!p)
			return (NULL);
		p[0] = 0;
		return (p);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while ((char)s[start] && i < len)
		p[i++] = (char)s[start++];
	p[i] = 0;
	return (p);
}
