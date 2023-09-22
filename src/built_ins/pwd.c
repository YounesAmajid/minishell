/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/22 01:32:01 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"



void pwd(t_env **env)
{
    char *pwd;
    (void)env;
    pwd = get_env_var(env, "PWD");
    // pwd = getcwd(NULL, 0);
    if (pwd)
    {
        ft_putstr_fd(pwd, STDOUT_FILENO);
        ft_putstr_fd("\n", STDOUT_FILENO);
    }
}
