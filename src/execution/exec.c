/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 04:21:58 by asabri            #+#    #+#             */
/*   Updated: 2023/09/18 00:37:29 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void execution(t_tree *tree,t_env **env,char **_env)
{
    if (tree->type == PIPE)
        exec_pipe(tree,*env,_env);
    else if (tree->type == WORD)
        exec_redir(tree,*env,_env);
}