/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:31:25 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/18 18:00:12 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_front(t_heap **lst, t_heap *p)
{
	if (!p || !lst)
		return ;
	p->next = *lst;
	*lst = p;
}

void	store_addr(char *s, t_data *data)
{
	t_heap	*p;

	p = malloc(sizeof(t_heap));
	if (!p)
	{
		free(s);
		free_everything(data);
	}
	p->address = s;
	p->next = NULL;
	ft_lstadd_front(&data->heap, p);
}
void	*ft_malloc(size_t size, t_data *data)
{
	void	*allocated;
	t_heap	*p;

	p = malloc(sizeof(t_heap));
	if (!p)
	{
		write(2, "fatal error: cannot allocate memory\n", 37);
		free_everything(data);
	}
	allocated = malloc(size);
	if (!allocated)
	{
		write(2, "fatal error: cannot allocate memory\n", 37);
		free(p);
		free_everything(data);
	}
	p->address = allocated;
	p->next = NULL;
	ft_lstadd_front(&data->heap, p);
	return (allocated);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}