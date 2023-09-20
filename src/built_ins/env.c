/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:11 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/19 17:51:19 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void my_env(t_env **env)
{
    
    if(!*env)
        return ;
    while (*env)
    {
        if ((*env)->val)
            printf("%s=%s\n", (*env)->var, (*env)->val);
        *env = (*env)->next;
    }
    _status(0);
}
