/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:55:24 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/05 22:49:05 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_strcpy(char *s1, char *s2)
{
	int i;
	
	if (!s1 || !s2) return (NULL);
	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

size_t ft_strlen(char *str)
{
	int i;

	if (!str) return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int count;
	char *ptr;

	count = ft_strlen(str);
	ptr  = (char *)malloc(sizeof(char) * count + 1);
	if (ptr)
		ft_strcpy(ptr, str);
	return (ptr);
	
}

int is_space(char c)
{
    if (c == 32 || c >= 9 && c <= 13) return (1);
    return (0);
}

int is_char(char c)
{
    int i;

    i = 0;
    if (((c >= 'a' && c <= 'z')
         || (c >= 'A' && c<= 'Z'))) return (1);
    return (0);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	if (!s) return (NULL);
	slen = ft_strlen(s);
	if (start > slen) return (ft_strdup(""));
	if (len > slen)
	len = slen - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr) return (NULL);
	i = 0;
	while (i < len && s[i] && start < slen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
