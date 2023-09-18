/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/18 01:56:18 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"



void ft_add_to_val(t_env **env, char *key)
{
    // Check environment list for existing key
    if (env == NULL) return ;
    while (*env) {
        if (strcmp((*env)->var, key) == 0) {
            // Here, free the old value and replace with new one
            (*env)->val = ft_strjoin((*env)->val, "/..");
            return;
        }
        env = &(*env)->next;
    }
}

void update_pwd(t_env **env)
{
    char *old_pwd;
    char *pwd;

    old_pwd = get_env_var(env, "PWD");
    set_env_var(env, "OLDPWD", old_pwd);
    pwd = getcwd(NULL, 0);
    if (pwd)
	{
        set_env_var(env, "PWD", pwd);
        free(pwd);
    }
    else if (!pwd)
	{
		ft_add_to_val(env, "OLDPWD");
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n", STDOUT_FILENO);
	}
}

void	pwd()
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		ft_putstr_fd(current, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_global_exit = 0;
	}
}
