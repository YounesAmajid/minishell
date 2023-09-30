/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:48:47 by asabri            #+#    #+#             */
/*   Updated: 2023/09/28 12:34:07 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	*ft_malloc(size_t size, int mode)
{
	static t_malloc	*head;
	static t_malloc	*env;
	void			*data;

	if (mode == 1)
	{
		data = malloc(size);
		if (!data)
			return (listclear(&head), exit(1), data);
		addfront(&head, newmalloc(data));
		return (data);
	}
	else if (mode == 2)
	{
		data = malloc(size);
		if (!data)
			return (listclear(&env), exit(1), data);
		addfront(&env, newmalloc(data));
		return (data);
	}
	else if (mode == 0)
		listclear(&head);
	else if (mode == 3)
		listclear(&env);
	return (NULL);
}
