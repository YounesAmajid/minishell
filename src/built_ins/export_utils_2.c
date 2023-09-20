/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:38:09 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/20 01:38:38 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int search_lenght(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i]) 
	{
		if (s[i] == c) return (i);
		i++;
	}
	return (i);
}

int ft_after_equ(char *str, char c)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] == c) if (str[i + 1] != '\0') return (1);
	return (0);
}
int check_dupl(char *str, t_env *env)
{
	while (env)
	{
		if ((strcmp(env->var, str) == 0))
			return (1);
		env = env->next;
	}
	return (0);
}

int search_after_equ(char *str)
{
	int i;

	i = 0;
	while (str[i++]) if (str[i] == '=' && str[i + 1] == '\0') return (1);
	return (0);
}

char *ft_strcpy(char *s1, char *s2, int len)
{
	int i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}