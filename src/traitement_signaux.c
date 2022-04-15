/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_signaux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:49:37 by ccartet           #+#    #+#             */
/*   Updated: 2022/04/07 10:49:37 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coquillette.h"

void	terminal_handler(int end)
{
	int						fd_term;
	struct termios			term_minishell;
	static struct termios	term_before;

	fd_term = ttyslot();
	if (isatty(fd_term))
		fprintf(stderr, "tty : %s\n", ttyname(fd_term));
	if (end)
	{
		tcsetattr(fd_term, TCSANOW, &term_before);
		return ;
	}
	tcgetattr(fd_term, &term_before);
	term_minishell = term_before;
	term_minishell.c_cc[VQUIT] = 0;
	tcsetattr(fd_term, TCSANOW, &term_minishell);
}

void	signal_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	static int	prompt = 1;

	if (sig == SIGUSR1)
	{
		prompt = ft_switch(prompt);
		return ;
	}
	if (sig == SIGQUIT)
		return ;
	if (prompt)
		ft_putstr_fd("\n\e[34mcoquillette0.1>\e[0m", 1);
	rl_replace_line("", 0);
}

void	init_sigact(struct sigaction *act)
{
	terminal_handler(0);
	act->sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	act->sa_sigaction = signal_handler;
	sigaction(SIGINT, act, NULL);
	sigaction(SIGQUIT, act, NULL);
	sigaction(SIGUSR1, act, NULL);
}
