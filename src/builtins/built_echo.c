/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:58:18 by ccartet           #+#    #+#             */
/*   Updated: 2022/03/27 17:57:58 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	built_echo(char **cmd_arg, int fd)
{
	int		nl;
	int		i;
	char	*new;

	nl = 1;
	i = 1;
	if (cmd_arg[i][0] == '-' && cmd_arg[i][1] == 'n')
	{
		if (cmd_arg[i][1] == 'n')
			nl = 0;
		else
		{
			ft_putendl_fd("echo : invalid option", 2);
			return ;
		}
		i++;
	}
	while (cmd_arg[i])
	{
		//new = dollar_searcher(cmd_arg[i]);
		ft_putstr_fd(cmd_arg[i], fd);
		ft_putchar_fd(' ', fd);
		//free(new);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', fd);
}
// echo ne s'arrete pas s'il trouve un espace !!