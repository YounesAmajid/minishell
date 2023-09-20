/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/20 04:44:37 by yamajid          ###   ########.fr       */
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
    t_env *current = *env;
    while (current) {
        if (strcmp(current->var, key) == 0)
        {
            current->val = NULL;
            current->val = strdup(value);
            return;
        }
        current = current->next;
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
int ft_check_for_cd(char **argv, t_env **env)
{
    if (argv[0] && argv[1])
    {
        if (access(argv[1], F_OK))
        {
            ft_putstr_fd("minishell cd: ", STDERR_FILENO);
            ft_putstr_fd(argv[1], STDERR_FILENO);
            ft_putstr_fd(" : no such file or directory \n", STDERR_FILENO);
            return (1);
        }
        else if ((access(argv[1], X_OK) == 0 && access(argv[1], W_OK) == 0 && access(argv[1], R_OK) == 0))
        {
            if (chdir(argv[1]) == 0)
                return (update_pwd(env, argv), 1);
        }
        else if ((access(argv[1], X_OK) != 0 || access(argv[1], W_OK) != 0 || access(argv[1], R_OK) != 0))
        {
            ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
            ft_putstr_fd(argv[1], STDERR_FILENO);
            ft_putstr_fd(" : Permission denied \n", STDERR_FILENO);
            return (1);
        }
    }
    return (0);
}

void cd_command(char **argv, t_env **env)
{
    char *str;

    if (argv[1] != NULL)
    {
        if (ft_check_for_cd(argv, env) == 1) return ;
        if (chdir(argv[1]) == 0)
        {
            set_env_var(env, "PWD", argv[1]);
            return;
        }
        else
        {
            printf("minishell: can't change to directory %s\n", argv[1]);
            return;
        }
    }
    else if (argv[0] && argv[1] == NULL)
    {
        if (chdir(str) == 0)
        {
            str = get_env_var(env, "HOME");
            set_env_var(env, "PWD", str);
            return ;
        }
        else
            printf("minishell: can't change to home directory\n");
    }
    return ;
}
// cd tmp/cd ..
// cd 
// 