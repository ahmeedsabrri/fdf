/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:47 by asabri            #+#    #+#             */
/*   Updated: 2022/11/04 12:00:07 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		n;
	size_t	i;
	char	*dp;
	char	*sp;

	i = 0;
	n = (int) len - 1;
	dp = (char *)dst;
	sp = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n >= 0)
		{
			dp[n] = sp[n];
			n--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
