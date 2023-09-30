/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:19:32 by asabri            #+#    #+#             */
/*   Updated: 2023/09/28 17:55:36 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_dup(int fd, t_token_type type)
{
	if (type == ROUT || type == APPEND)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (perror("dup2 error"), exit(1), 0);
	}
	else
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			return (perror("dup2 error"), exit(1), 0);
	}
	return (close(fd), 1);
}

int	redir_creation(t_redir *redir, t_env *env)
{
	int	fd;

	(void)env;
	if (!redir)
		return (0);
	if (redir->type != HEREDOC)
	{
		fd = open(redir->open_file, redir->file_flages, 0664);
		if (fd == -1)
			return (fd_printf(2, "Minishell: %s: No such file or directory\n", 
					redir->open_file), exit(1), 0);
		return (redir_dup(fd, redir->type));
	}
	else
	{
		if (dup2(redir->in_fd, STDIN_FILENO) == -1)
			return (perror(" dup2 Error"), exit(1), 0);
		return (close(redir->in_fd), 1);
	}
	return (1);
}

int	run_cmd(t_tree *tree, t_env **env, char **arg)
{
	while (((t_simplecmd *)tree)->redir_list && 
		check_redir(((t_simplecmd *)tree)->redir_list->type) && 
		redir_creation(((t_simplecmd *)tree)->redir_list, *env))
		((t_simplecmd *)tree)->redir_list = 
			((t_simplecmd *)tree)->redir_list->next;
	if (arg[0])
		exec_cmd(tree, *env, arg);
	return (0);
}

void	exec_redir(t_tree *tree, t_env **env)
{
	char	**arg;
	char	**args;
	int		list_len;

	arg = list_to_array_env(((t_simplecmd *)tree)->simplecmd, &list_len);
	if (is_bulting(arg[0]))
	{
		redir_creation(((t_simplecmd *)tree)->redir_list, *env);
		if (built_ins(arg, env, list_len) || !arg[0])
			return ;
	}
	args = list_to_array(((t_simplecmd *)tree)->simplecmd, &list_len);
	run_cmd(tree, env, args);
}
