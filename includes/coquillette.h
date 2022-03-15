/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coquillette.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:21:14 by njaros            #+#    #+#             */
/*   Updated: 2022/03/08 16:46:52 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COQUILLETTE_H
# define COQUILLETTE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_env
{
    char    *name;
    char    *value;
}               t_env;

typedef struct pipex_data
{
	int		pipefd_in[2];
	int		pipefd_out[2];
	char	**envp;
	char	**cmd_path;
	char	**cmd;
}	pipex_data;

typedef struct s_pipe
{
    int     infile;
    int     outfile;
    char    **path;
    char    **cmd1_arg;
    char    *cmd1;
    char    **cmd2_arg;
    char    *cmd2;
}               t_pipe;

// Gestion initiales de l'entrée utilisateur

void	handler(int sig, siginfo_t *siginfo, void *ucontext);
char	*rl_get(char *line_read);

// Fonctions d'initialisation

int 	init_pipex_data(pipex_data *data, char **envp);
void	init_sigact(struct sigaction *act);

// Fonctions utiles pour tout le cursus (bonne idée de les intégrer à la libft)

int		get_fd_rdonly(char *entry);

//pipe
int     pipex(int argc, char *argv[], char **envp);
void    init(t_pipe *pip, char **argv);
void    child_one(t_pipe *pip, int *fd, char **envp);
void    child_two(t_pipe *pip, int *fd, char **envp);
char    *get_cmd(char *cmd, char **path);
//
void    feel_free(t_pipe *pip);
void	ft_free(char **tab);
void	error(char *msg);
int		error2(int err);

#endif