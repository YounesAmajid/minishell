/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/28 21:04:15 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_env **env)
{
	char	*pwd;

	pwd = get_env_var(env, "PWD");
	if (pwd)
		fd_printf(1, "%s\n", pwd);
	else
	{
		pwd = getcwd(NULL, 0);
		fd_printf(1, "%s\n", pwd);
		free(pwd);
	}
}
