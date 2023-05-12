/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:58:49 by asabri            #+#    #+#             */
/*   Updated: 2023/05/12 22:04:38 by asabri           ###   ########.fr       */
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

	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*(lst));
		ptr->next = new;
	}
}