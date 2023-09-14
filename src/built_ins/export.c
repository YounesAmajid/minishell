/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:20 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/14 08:29:27 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_lst_size(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}
int needed_first(char c)
{
	if (((c == '_' ) || ft_isalpha(c))) return (1);
	return (0);
}

t_env *ft_lst_last(t_env *env)
{
	if (env->next == NULL)
		return (env);
	while (env->next)
		env = env->next;
	return (env);
}


t_env *ft_lst_new(char *str, char *val)
{
	t_env *head;

	head = (t_env *)malloc(sizeof(t_env));
	if (!head)
		return (NULL);
	head->var = str;
	if (val == NULL)
		head->val = NULL;
	else
		head->val = val;
	head->next = NULL;
	return (head);
}

void	ft_lstaddback(t_env **env, t_env *newnode)
{
	t_env	*lastnode;

	if (!env || !newnode)
		return ;
	if (!*env)
	{
		*env = newnode;
		return ;
	}
	lastnode = ft_lst_last(*env);
	lastnode->next = newnode;
}

int ft_stchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i++]) if (s[i] == c) return (1);
	return (0);
}

int search_lenght(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i]) 
	{
		if (s[i] == c) return (i);
		i++;
	}
	return (i);
}

int ft_after_equ(char *str, char c)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] == c) if (str[i + 1] != '\0') return (1);
	return (0);
}
int check_dupl(char *str, t_env *env)
{
	while (env)
	{
		if ((strcmp(env->var, str) == 0))
			return (1);
		env = env->next;
	}
	return (0);
}

int search_after_equ(char *str)
{
	int i;

	i = 0;
	while (str[i++]) if (str[i] == '=' && str[i + 1] == '\0') return (1);
	return (0);
}

char *ft_strcpy(char *s1, char *s2, int len)
{
	int i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char *ft_cut(char *str, char c)
{
	int i;
	char *ptr;

	ptr = NULL;
	i = search_lenght(str, c);
	ptr = ft_strcpy(ptr, str, i);
	return (ptr);
}

void change_value_if_not(t_env **env, char *str)
{
	t_env *ptr;

	ptr = *env;
	while (ptr)
	{
		if (strcmp(ptr->var, ft_cut(str, '=')) == 0)
		{
			printf("%s--\n", ft_cut(str, '='));
			if (ptr->val != NULL)
			{
				printf("fuck\n");
				ptr->val = "\0";
			}
			else if ((ptr->val == NULL || ptr->val[0] == '\0'))
			{
				ptr->val = ft_substr(str, search_lenght(str, '=') + 1, 
					ft_strlen(str) - search_lenght(str, '='));
				printf("hereeee\n");				
			}
			else
				return ;
		}	
		ptr = ptr->next;
	}
}

void change_value_if_exist(t_env **env, char *str)
{
	t_env *ptr;

	ptr = *env;
	while (ptr)
	{
		if (strcmp(ptr->var, ft_cut(str, '=')) == 0)
		{
			if (ptr->val == NULL || ptr->val[0] == '\0')
				ptr->val = ft_substr(str, search_lenght(str, '=') + 1,
					ft_strlen(str) - search_lenght(str, '='));
			return ;
		}	
		ptr = ptr->next;
	}
}

int ft_search_for_plus(char *str, char c)
{
	int i;

	i = 0;
	while (str[i++]) 
		if (str[i] == c && str[i + 1] == '=') return (1);
	return (0);
}
// int chek_var(char *str)
// {
	
// }
void change_value_for_plus(t_env **env, char *str)
{
	t_env *ptr;

	ptr = *env;
	while (ptr)
	{
		if (ft_strcmp(ptr->var, ft_cut(str, '+')) == 0)
		{
			if (!ft_after_equ(str, '=') && ptr->val == NULL)
				ptr->val = "\0";
			else if (ft_after_equ(str, '=') && ptr->val == NULL)
				ptr->val = ft_substr(str, search_lenght(str, '=') + 1, ft_strlen(str) - search_lenght(str, '='));
			else if (ft_after_equ(str, '=') && ptr->val[0] != '\0')
				ptr->val = ft_strjoin(ptr->val, ft_substr(str, search_lenght(str, '=') + 1,
					ft_strlen(str) - search_lenght(str, '=')));
			return ;
		}	
		ptr = ptr->next;
	}
	if (needed_first(str[0]) && !ft_after_equ(str, '='))
		ft_lstaddback(env, ft_lst_new(ft_substr(str, 0, search_lenght(str, '=') - 1), "\0"));
	else if (needed_first(str[0]) && ft_after_equ(str, '='))
		ft_lstaddback(env, ft_lst_new(ft_substr(str, 0, search_lenght(str, '=') - 1),
			ft_substr(str, search_lenght(str, '=') + 1, 
				ft_strlen(str) - search_lenght(str, '='))));
	else
		return ;
	
}

int if_error(char *str)
{
	if (((str[ft_strlen(str) - 1] == '_' ) || 
		ft_isalnum(str[ft_strlen(str) - 1]))) return (1);
	return (0);
		
}

int check_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
		{
			if ((str[i] == '+' && str[i + 1] == '=' )|| str[i] == '=')
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}

int  export_cases(t_env **env, char *str)
{
	if (needed_first(str[0]) == 0 || check_string(ft_cut(str, search_lenght(str, '=') - 1)) == 0)
		return (printf("minishell: export: '%s': not a valid identifier\n", str), 0);
	if (((check_dupl(ft_cut(str, '='), *env)) || ft_search_for_plus(str, '+')))
	{
		if (!ft_stchr(str, '='))
			return (0);
		else if (ft_search_for_plus(str, '+'))
			change_value_for_plus(env, str);
		else if (!ft_after_equ(str, '='))
			change_value_if_not(env, ft_cut(str, '='));
		else if (ft_after_equ(str, '=')) 
			change_value_if_exist(env, str);
	}
	return (1);
}

int export(char **argv, t_env **env, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] != NULL)
		{
			if (needed_first(argv[i][0]) == 0 || check_string(ft_cut(argv[i], search_lenght(argv[i], '=') - 1)) == 0)
				return (printf("minishell: export: '%s': not a valid identifier\n", argv[i]), 0);
			else if (((check_dupl(ft_cut(argv[i], '='), *env)) || ft_search_for_plus(argv[i], '+')))
			{
				if (!ft_stchr(argv[i], '='))
					return (0);
				else if (ft_search_for_plus(argv[i], '+'))
					change_value_for_plus(env, argv[i]);
				else if (!ft_after_equ(argv[i], '='))
					change_value_if_not(env, ft_cut(argv[i], '='));
				else if (ft_after_equ(argv[i], '=')) 
					change_value_if_exist(env, argv[i]);
			}
			else if ((needed_first(argv[i][0]) && !ft_stchr(argv[i], '=')))
			{
				if (if_error(argv[i]) == 1 && check_string(argv[i]) == 1)
					ft_lstaddback(env, ft_lst_new(argv[i], NULL));
				else
					return (printf("minishell: export: '%s': not a valid identifier\n", argv[i]), 0);
			}
			else if ((needed_first(argv[i][0]) && !ft_after_equ(argv[i], '=')))
				ft_lstaddback(env, ft_lst_new(ft_substr(argv[i], 0 , search_lenght(argv[i], '=')), "\0"));
			else if ((ft_stchr(argv[i], '=')) && (needed_first(argv[i][0]) && ft_after_equ(argv[i], '=')))
					ft_lstaddback(env, ft_lst_new(ft_substr(argv[i], 0, search_lenght(argv[i], '=')), 
						ft_substr(argv[i], search_lenght(argv[i], '=') + 1,
							ft_strlen(argv[i]) - search_lenght(argv[i], '='))));
		}
		i++;
	}
	return (1);
}

void sort_list_for_export(t_env **env)
{
	t_env *ptr;
	char *var;
	char *val;
	int j;

	ptr = *env;
	int i = ft_lst_size(*env);
	while (i > 0)
	{
		j = i - 1;
		while (j--)
		{
			if (ft_strncmp((*env)->var, (*env)->next->var, 1) > 0)
			{
				var = (*env)->var;
				val = (*env)->val;
				(*env)->var = (*env)->next->var;
				(*env)->val = (*env)->next->val;
				(*env)->next->var = var;
				(*env)->next->val = val;
			}
			(*env) = (*env)->next;
		}
		i--;
		*env = ptr;
		
	}
}

void export_alone(t_env *env)
{

	sort_list_for_export(&env);
	while(env)
	{
		if (env->val == NULL)
			printf("declare -x %s\n", env->var);
		else
			printf("declare -x %s=\"%s\"\n", env->var, env->val);
		env = env->next;
	}
}
