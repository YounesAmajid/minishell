/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/20 01:30:37 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"



void pwd(t_env **env)
{
    char *pwd;

    pwd = get_env_var(env, "PWD");;
    if (pwd)
    {
        ft_putstr_fd(pwd, STDOUT_FILENO);
        ft_putstr_fd("\n", STDOUT_FILENO);
    }
}
