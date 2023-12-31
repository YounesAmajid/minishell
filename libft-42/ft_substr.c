/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:31:38 by asabri            #+#    #+#             */
/*   Updated: 2023/09/27 00:46:29 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_env(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		p = ft_malloc(sizeof(char) * 1, 2);
		if (!p)
			return (NULL);
		p[0] = 0;
		return (p);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = ft_malloc(sizeof(char) * (len + 1), 2);
	if (!p)
		return (NULL);
	i = 0;
	while ((char)s[start] && i < len)
		p[i++] = (char)s[start++];
	p[i] = 0;
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		p = ft_malloc(sizeof(char) * 1, 1);
		if (!p)
			return (NULL);
		p[0] = 0;
		return (p);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = ft_malloc(sizeof(char) * (len + 1), 1);
	if (!p)
		return (NULL);
	i = 0;
	while ((char)s[start] && i < len)
		p[i++] = (char)s[start++];
	p[i] = 0;
	return (p);
}
