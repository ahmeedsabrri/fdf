/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:52:11 by asabri            #+#    #+#             */
/*   Updated: 2023/05/14 15:11:18 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hextodec(char *str)
{
	int	ret;
	int	hex;
	int	len;

	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	len = ft_strlen(str);
	ret = 0;
	hex = 1;
	while (len-- && len <= 6)
	{
		if (ft_isdigit(str[len]))
			ret += (str[len] - 48) * hex;
		else if (str[len] >= 'A' && str[len] <= 'F')
			ret += (str[len] - 55) * hex;
		else if (str[len] >= 'a' && str[len] <= 'f')
			ret += (str[len] - 87) * hex;
		hex *= 16;
	}
	return (ret);
}