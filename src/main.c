/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:13:44 by mallard           #+#    #+#             */
/*   Updated: 2017/11/04 21:09:07 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		ft_ini(void)
{
	char			*name;
	struct termios	term;

	if (!(name = getenv("TERM")))
		return (0);
	if ((tgetent(NULL, name)) == 0)
		return (0);
	if (tcgetattr(0, &term) == -1)
		return (0);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);
	return (1);
}

int		ft_exit(void)
{
	struct termios		term;

	if (tcgetattr(0, &term))
		return (0);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (0);
	//signal(SIGWINCH, SIG_IGN);
	signal(SIGINT, SIG_IGN); // interruption
	signal(SIGQUIT, SIG_IGN); // instruction QUIT
	signal(SIGTSTP, SIG_IGN); // demande suspention clavier
	signal(SIGTTIN, SIG_IGN); // lecture arriere terminal
	signal(SIGTTOU, SIG_IGN); // ecriture arriere terminal
	signal(SIGCHLD, SIG_IGN);
	return (1);
}

int		main(int ac, char **av, char **env)
{
	char			*name;
	struct termios	term;
	extern t_all	all;

	if (ac > 1)
	{
		if (*env)
		{
			char_del(av, 0, 0);
			if ((ft_ini() == 0))
				return (1);
			all.size = ini_size(max_size(av));
			all.lst = arg_set(av);
			print_lst(all.lst, all.size);
			voir_touche(all.lst, all.size);
			if (ft_exit() == 0)
				return (1);
		}
		else
			ft_putendl("env is not enable");
	}
	else
		ft_putendl("Not enough agument");
	return (0);
}
