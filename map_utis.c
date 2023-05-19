/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:58:49 by asabri            #+#    #+#             */
/*   Updated: 2023/05/17 11:34:03 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lstsize(t_map *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_map	*ft_lstnew(int **content)
{
	t_map		*new;

	new = ft_malloc(sizeof (t_map), 1);
	if (!new)
		return (NULL);
	new->x = content;
	new->next = NULL;
	return (new);
}

t_map	*ft_lstlast(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst ->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*ptr;
	int		len;

	len = 0;
	ptr = *lst;
	(!*lst) && (*lst = new);
	if (ptr)
	{
		len = mtrlen((void **)(*lst)->x);
		while (ptr->next)
		{
			if (len != mtrlen((void **)new->x))
				ft_malloc(0, 0);
			ptr = ptr->next;
		}
		ptr->next = new;
	}
}
