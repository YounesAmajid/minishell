/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:46:30 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/28 19:36:23 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printf_error(char **argv)
{
	printf("exit\n");
	printf("minishell: exit: %s: numeric argument required\n", argv[1]);
}

void	my_env(t_env **env)
{
	t_env	*ptr;

	ptr = *env;
	if (!ptr)
		return ;
	while (ptr)
	{
		if ((ptr)->val != NULL)
			printf("%s=%s\n", (ptr)->var, (ptr)->val);
		ptr = (ptr)->next;
	}
	_status(0);
}
