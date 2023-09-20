/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/20 03:38:00 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void update_pwd(t_env **env, char **argv)
{
    char *old_pwd;
    char *new_pwd;
    char *n_pwd;
    
    old_pwd = get_env_var(env, "PWD");
    if (old_pwd)
        set_env_var(env, "OLDPWD", old_pwd);
    new_pwd = getcwd(NULL, 0);
    if (new_pwd)
        set_env_var(env, "PWD", new_pwd);
    else
    {
        n_pwd = get_env_var(env, "PWD");
        if (ft_strcmp(argv[1], ".") == 0)
            set_env_var(env, "PWD", ft_strjoin(n_pwd, "/."));
        else if (ft_strcmp(argv[1], "..") == 0)
            set_env_var(env, "PWD", ft_strjoin(n_pwd, "/.."));
        ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n", STDERR_FILENO);
    }
}

void pwd(t_env **env)
{
    char *pwd;
    
    pwd = get_env_var(env, "PWD");;
    if (pwd)
    {
        ft_putstr_fd(pwd, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
}
