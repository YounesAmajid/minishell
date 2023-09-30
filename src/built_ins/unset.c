/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:46:10 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/28 21:12:29 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	valide_str(char *str)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error(char *argv)
{
	if (needed_first(argv[0]) == 0 
		|| (if_error(argv) == 0 && !valide_str(argv)))
	{
		printf("minishell: unset: `%s': not a valid identifier\n", argv);
		return (1);
	}
	return (0);
}

void	unset_var(t_env **env, char **argv, int i)
{
	t_env	*ptr;
	t_env	*prev;

	prev = NULL;
	ptr = *env;
	if (error(argv[i]) == 1)
		return ;
	while (ptr)
	{
		if (ft_strcmp(argv[i], ptr->var) == 0)
		{
			if (prev == NULL)
				*env = ptr->next;
			else
				prev->next = ptr->next;
			free(ptr->var);
			if (ptr->val)
				free(ptr->val);
			free(ptr);
			break ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}

void	unset(t_env **env, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		unset_var(env, argv, i);
		i++;
	}
}
