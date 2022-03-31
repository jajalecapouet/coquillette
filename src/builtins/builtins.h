/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:38:46 by ccartet           #+#    #+#             */
/*   Updated: 2022/03/30 15:10:35 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/param.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <termios.h>
# include <fcntl.h>
# include "../../includes/libft.h"

typedef struct s_env
{
    char    *name;
    char    eg;
    char    *value;
	int		rank;
}               t_env;

long	g_cmd_ret;

//builtins
void	builtins(char **cmd_arg, t_list *env, int fd);
t_list	*init_envp(char **envp);
t_env	*create_struct(char *env);
t_env	*find_env_var(t_list *env, char *to_search);
char	*rl_get(char *line_read);
int	    print_err(char *str, int err);
char	*ft_strmchr(char *s, char *charset);
long	ft_atol(const char *str);
//
int	    built_cd(char **cmd_arg, t_list *env, int fd);
int	    to_home(void);
int 	change_pwd_oldpwd(char *oldpwd, t_list *env);
int 	replace_or_create(t_list *env, t_env *var, char *var_name, char *path);
//
void	built_echo(char **cmd_arg, int fd);
//
int	    built_env(t_list *env, char **cmd_arg, int fd);
//
void	built_exit(char **cmd_arg);
int	    check_arg(char *arg);
//
int	    built_export(char **cmd_arg, t_list *env, int fd);
void	print_export(t_list *env, int size, int fd);
void    init_rank(t_list *env, int *size);
//
int 	built_pwd(char **cmd_arg, int fd);
//
void	built_unset(char **cmd_arg, t_list *env);
t_list	*find_link(t_list *env, char *to_search);
void	env_del(t_list *env, t_list *to_del);

#endif