/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:43:38 by njaros            #+#    #+#             */
/*   Updated: 2022/03/27 11:54:21 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coquillette.h"

// char	*found_cmd(char *entry)
// {
// 	char	*env;
// 	char	*cmd;
// 	char	**path_tab;
// 	int		i;

// 	i = -1;
// 	while (entry[++i])
// 		if (entry[i] == '/')
// 			return (entry);
// 	env = getenv("PATH");
// 	path_tab = ft_split(env, ':');
// 	free(env);
// 	cmd = get_cmd(entry, path_tab);
// 	ft_free(path_tab);
// 	free(entry);
// 	return (cmd);
// }

// int	is_spechar(char c)
// {
// 	if (c == ' ')
// 		return (1);
// 	if (c == '$')
// 		return (1);
// 	if (c == '|')
// 		return (1);
// 	if (c == '>')
// 		return (1);
// 	if (c == '<')
// 		return (1);
// 	return (0);
// }

// int	parsing_line(char *line, pipex_data *data, int *begin)
// {
// 	int		i;
// 	int		in_dquote;
// 	int		in_quote;

	
// 	in_quote = 0;
// 	in_dquote = 0;
// 	i = -1;
// 	while (line[++i])
// 	{
// 		while (line[i] == ' ')
// 			i++;
// 		while (line[i] && !(is_spechar(line[i]) && !in_dquote && !in_quote))
// 		{
// 			if (line[i] == 34 && !in_quote) // 34 = "
// 				in_dquote = ft_switch(in_dquote);
// 			if (line[i] == 39 && !in_dquote) // 39 = ' 
// 				in_quote = ft_switch(in_quote);
// 		}
// 		if (line[i] == ' ' || line[i])
// 			data->path = found_cmd(ft_substr(line, 0, i));
// 	}
// 	return (0);
// }

// char	*next_pipe(char *line, pipex_data *data)
// {
// 	char	*next_cmd;

// 	if (data->next_pipe_pos == 0)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	next_cmd = ft_strdup(&line[data->next_pipe_pos + 1]);
// 	free(line);
// 	data->pipefd_in[0] = data->pipefd_out[0];
// 	data->pipefd_in[1] = data->pipefd_out[1];
// 	if (pipe(data->pipefd_out) == -1)
// 		return (NULL);
// 	return (next_cmd);
// }

// int	execpipe(pipex_data *data)
// {
// 	pid_t	fork_pid;
// 	int		err;

// 	err = 0;
// 	fork_pid = fork();
// 	if (fork_pid == -1)
// 		return (error2(-1));
// 	if (fork_pid == 0)
// 	{
// 		if (dup2(data->pipefd_in[0], STDIN_FILENO) == -1)
// 			return (error2(-1));
// 		if (dup2(data->pipefd_out[1], STDOUT_FILENO) == -1)
// 			return (error2(-1));
// 		close(data->pipefd_out[0]);
// 		close(data->pipefd_in[1]);
// 		err = execve(data->path, data->argv, data->envp);
// 		return (err);
// 	}
// 	close(data->pipefd_in[0]);
// 	close(data->pipefd_out[1]);
// 	waitpid(fork_pid, NULL, 0);
// 	return (err);
// }

// void	exec()
// {
	
// }

// void	test_multipipe()
// {
// 	int		pip_nb;
// 	t_pipe	pip;
// 	int		fd[2];
// 	int		tmp_fd;
// 	pid_t	fork_pid;
	
// 	pip_nb = 2; // recuperer le nb de pipe => parsing
// 	while (pip_nb > 0)
// 	{
// 		if (pipe(fd) == -1)
//       		error("pipe");
// 		fork_pid = fork(); // ou builtins
// 			error("fork");
// 		if (fork_pid == 0)
// 		{
// 			if (dup2(pip->infile, STDIN_FILENO) == -1)
//        			error("dup");
//     		close(fd[0]);
//     		if (dup2(fd[1], STDOUT_FILENO) == -1)
//         		error("dup");
//     		close(pip->infile);
//     		if (execve(pip->cmd1, pip->cmd1_arg, envp) == -1)
//         		error("execve");
// 		}
// 		pip_nb--;
// 	}
// }