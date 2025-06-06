/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:02:07 by iezzam            #+#    #+#             */
/*   Updated: 2025/04/23 16:52:41 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/execution.h"

static void	run_child_process(t_cmd *command, t_env **env, \
	int *exit_status, t_pipex_data *data)
{
	char	**envp;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (handle_file_redirection(command, &data->infile, &data->outfile, 0) \
	== -1)
	{
		(cleanup_child_fds(data), exit(1));
	}
	envp = ft_env_create_2d(*env);
	(cleanup_child_fds(data));
	execute_cmd(command->cmd, envp, exit_status);
}

static int	retrieve_exit_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			write(1, "\n", 1);
			return (130);
		}
		if (WTERMSIG(status) == SIGQUIT)
		{
			write(1, "Quit: 3\n", 8);
			return (131);
		}
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

void	execution_cmd(t_cmd *command, char **cmd, t_env **env, int *exit_status)
{
	char			**cmd_argv;
	pid_t			pid;
	t_pipex_data	data;

	data.f_fd = 1;
	data = (t_pipex_data){-1, -1, {-1, -1}, -1, 1, 0, 0, -1, 0};
	cmd_argv = cmd;
	if (ft_execute_builtins(cmd_argv, env, exit_status, &data) == SUCCESS)
		return ;
	(signal(SIGINT, SIG_IGN), signal(SIGQUIT, SIG_IGN));
	pid = fork();
	if (pid < 0)
		(ft_print_err("Fork Error\n"), *exit_status = 1, exit(1));
	if (pid == 0)
		run_child_process(command, env, exit_status, &data);
	(cleanup_child_fds(&data));
	waitpid(pid, exit_status, 0);
	*exit_status = retrieve_exit_status(*exit_status);
}
