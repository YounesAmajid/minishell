/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:44:30 by asabri            #+#    #+#             */
/*   Updated: 2023/09/02 23:14:32 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *check_none_expand(char *str, int *index)
{
    int i;
    char *ptr;
    
    i = *index;
    while (str[i] && str[i] != '$')
		i++;
    ptr = ft_substr(str, *index , i - *index);
    *index = i - 1;
    return (ptr);
}

char *check_expand(char *str,t_env *env, int *i)
{
    int index;
    char *var;
    (void)env;
    index = *i + 1;
    if(str[index] && str[index] == '?')
    {
        *i = index;
        return (ft_itoa(g_global_exit));
    }
    if(str[index] && (str[index] == '_' || ft_isalpha(str[index])))
        index++;
    while(str[index] && (str[index] == '_' || ft_isalnum(str[index])))
        index++;
    var = ft_substr(str, *i + 1, index - *i - 1);
    *i = index - 1;
    while(env)
    {
        if(!ft_strcmp(env->var, var))
            return(ft_strdup(env->val));
        env = env->next;
    }
    return (NULL);
}
char *ft_expand(char *str,t_env *env)
{
    char *ptr;
    char *cmd;
    
    cmd = NULL;
    ptr = NULL;
    int i = -1;
    while(str[++i])
    {
        if (str[i] == '$')
            ptr = check_expand(str,env, &i);
        else
            ptr = check_none_expand(str, &i);
        cmd = ft_strjoin(cmd,ptr);
    }
    return (cmd);
}
