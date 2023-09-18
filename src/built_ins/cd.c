/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/18 01:48:14 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_home_path(t_env **env)
{
    char *str;

    str = NULL;
    while (*env)
    {
        if (ft_strcmp((*env)->var, "HOME") == 0)
        {
            str = (char *)malloc(sizeof((*env)->val));
            if (!str)
                return (NULL);
            str = (*env)->val;
        }
        (*env) = (*env)->next;
    }
    return (str);
}

void set_env_var(t_env **env, char *key, char *value)
{
    // Check environment list for existing key
    if (env == NULL) return ;
    while (*env) {
        if (strcmp((*env)->var, key) == 0) {
            // Here, free the old value and replace with new one
            (*env)->val = NULL;
            (*env)->val = strdup(value);
            return;
        }
        env = &(*env)->next;
    }
}

char *get_env_var(t_env **env, char *key)
{
    if (env == NULL) return NULL;
    while (*env)
    {
        if (strcmp((*env)->var, key) == 0) {
            return (*env)->val;
        }
        env = &(*env)->next;
    }
    return NULL;
}

int cd_command(char **argv, t_env **env)
{
    char *str;

    if (argv[1] != NULL)
    {
        if (argv[0] && argv[1])
        {
            if ((access(argv[1], X_OK) == 0 && access(argv[1], W_OK) == 0 && access(argv[1], R_OK) == 0))
            {
                if (chdir(argv[1]) == 0)
                {
                    update_pwd(env);
                    return 0;
                }
                else if (((access(argv[1], X_OK) != 0 || access(argv[1], W_OK) != 0 || access(argv[1], R_OK) != 0)))
                {
                    ft_putstr_fd("minishell: cd:", STDOUT_FILENO);
                    ft_putstr_fd(argv[1], STDOUT_FILENO);
                    ft_putstr_fd(" : Permission denied \n", STDOUT_FILENO);
                    return 0;
                }
            }
            else
            {
                ft_putstr_fd("minishell cd: ", STDOUT_FILENO);
                ft_putstr_fd(argv[1], STDOUT_FILENO);
                ft_putstr_fd(" : no such file or directory: \n", STDOUT_FILENO);
                return 0;
            }
        }
    }
    else
    {
        str = get_home_path(env);
        if (!str)
        {
            ft_putstr_fd("minishell: cd: HOME not set\n", STDOUT_FILENO);
            return 0;
        }
        if (!chdir(str)) 
        {
            // Update OLDPWD and PWD
            update_pwd(env);
            return 0;
        }
        else {
            // If getcwd() returns NULL, the directory doesn't exist. 
            char *cwd = getcwd(NULL, 0);
            if (!cwd) {
                return 1;
            }
            // Always free a string returned by getcwd() with argument NULL
            free(cwd);
        }
    }
    return 0;
}

void handle_cd_command(char **argv, t_env **env)
{
    int cd_fail_count = 0;
    int result = cd_command(argv, env);
    if (result == 1) {
        if (cd_fail_count == 0) {
            printf("cd: ..: No such file or directory\n");
        } else {
            printf("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n");
        }
        cd_fail_count++;
    } else {
        cd_fail_count = 0;
    }
}

// void cd_command(char **argv, t_env **env)
// {
//     char *str;

//     if (argv[1] != NULL)
//     {
//         if (argv[0] && argv[1])
//         {
//             if (chdir(argv[1]) == 0)
//             {
//                 if ((access(argv[1], X_OK) == 0 && access(argv[1], W_OK) == 0 && access(argv[1], R_OK) == 0))
//                 {
//                     update_pwd(env);
//                     return ;
//                 }
//                 else if ((access(argv[1], X_OK) != 0 || access(argv[1], W_OK) != 0 || access(argv[1], R_OK) != 0))
//                 {
//                     ft_putstr_fd("minishell: cd:", STDOUT_FILENO);
//                     ft_putstr_fd(argv[1], STDOUT_FILENO);
//                     ft_putstr_fd(" : Permission denied \n", STDOUT_FILENO);
//                     return ;
//                 }
//             }
//             else if (chdir(argv[1]) != 0)
//             {
//                 ft_putstr_fd("minishell cd: ", STDOUT_FILENO);
//                 ft_putstr_fd(argv[1], STDOUT_FILENO);
//                 ft_putstr_fd(" : no such file or directory: \n", STDOUT_FILENO);
//             }
//         }
//     }
//     else
//     {
//         str = get_home_path(env);
//         if (!str)
//         {
//             ft_putstr_fd("minishell: cd: HOME not set\n", STDOUT_FILENO);
//             return;
//         }
//         if (!chdir(str)) 
//         {
//             // Update OLDPWD and PWD
//             update_pwd(env);
//         }
//         else
//         {
//             printf("minishell: can't change to home directory\n");
//         }
//     }
//     return;
// }


