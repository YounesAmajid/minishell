/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:20 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/08 17:07:28 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: after tokenising test "string" and edit strtok
// int check_identifier(char *identifier)
// {
//     int i = 0;
    
//     while (identifier[i])
//     {
//         if (!((identifier[i] >= 'a' && identifier[i] <= 'z') ||
//               (identifier[i] >= 'A' && identifier[i] <= 'Z') ||
//               identifier[i] == '_'))
//         {
//             printf("'%s': not a valid identifier \n", identifier);
//             return (g_global_exit = 1, 1);
//         }
//         i++;
//     }
//     return (g_global_exit = 0, 0);
// }
// static void export_update(t_env **env, char *name, char *value)
// {
// 	t_env *current = find_env(*env, name);
// 	char **var;

// 	if (current) 
// 	{
// 		free(current->val);
// 		current->val = ft_strdup(value);
// 	}
// 	else
// 	{
// 		var = malloc(sizeof(char *) * 2);
// 		var[0] = ft_strdup(name);
// 		var[1] = ft_strdup(value);
// 		add_var_back(env, newvar(var));
// 	}
// }

int compare(char a, char b)
{
	if (a > b) return (0);
	return (1);
}

void sort_env_for_export(t_env **env)
{
	t_env *ptr;
	char *var;
	char *val;

	ptr = *env;
	while ((*env)->next)
	{
		if (compare((*env)->var[0], (*env)->next->var[0]) == 0)
		{
			var = (*env)->var;
			val = (*env)->val;
			(*env)->var = (*env)->next->var;
			(*env)->val = (*env)->next->val;
			(*env)->next->var = var;
			(*env)->next->val = val;
		}
		else
			*env = (*env)->next;
	}
	*env = ptr;
}

void export_alone(t_env *env)
{
	sort_env_for_export(&env);
	while(env)
	{
		printf("declare -x %s=\"\"\n", env->var);
		env = env->next;
	}
}

int export(char *variable, t_env **env)
{
	char **var = takevar(variable);

	if (!check_identifier(variable))
	{
		if (var)
		{
			export_update(env, var[0], var[1]);
			free(var[0]);
			free(var[1]);
			free(var);
		}
		else
			export_alone(NULL);
		return (g_global_exit = 0, 0);
	}
	return (g_global_exit = 1, 0);
}
