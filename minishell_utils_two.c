/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:38:38 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/05 17:39:23 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *last_node(t_lexer *lexer)
{
    if (lexer->next == NULL)
        return (lexer);
    while (lexer)
        lexer = lexer->next;
    return (lexer);
}

void lexer_add_back(t_lexer **lex, t_lexer *new)
{
    if (!(*lex) || !new)
        return ;
    if (!*lex)
    {
        *lex = new;
        return ;
    }
    else
    {
        *lex = last_node(*lex);
        (*lex)->next = new;
    }
}

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