/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:46 by ynakashi          #+#    #+#             */
/*   Updated: 2021/10/19 11:07:17 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned int	g_flag;

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		g_flag = ON;
	else if (sig == SIGUSR2)
		g_flag = OFF;
	if (kill(info->si_pid, SIGUSR1) == ERROR)
	{
		ft_putendl_fd(COLOR_R"KILL ERROR"COLOR_OFF, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	ft_init(void	handler(int sig, siginfo_t *info, void *ucontext))
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == ERROR)
		exit (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &act, NULL) == ERROR)
		exit (EXIT_FAILURE);
}

int	main(void)
{
	uint8_t	eight_bit;
	int		count;

	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	ft_init(handler);
	count = 7;
	eight_bit = 0;
	while (1)
	{
		pause();
		if (g_flag == ON || g_flag == OFF)
			eight_bit = eight_bit | (g_flag << count--);
		if (count == -1)
		{
			ft_putchar_fd(eight_bit, STDOUT_FILENO);
			count = 7;
			eight_bit = 0;
		}
	}
}
// In Unicode, the first some bits represent the byte number of the character.
// The terminal can read it, and if it is missing that bit of the byte number,
// it can hold the bit of information somewhere.
// When it receives up to the byte number,
// the terminal will output the character.

// a = 01100001
// 0ch;00000000
// 1gb;00000000
// 1gs;00000000(Shift the bit 7 times to the left.)
// 1ch;00000000(Compare 0ch and 1gs with |.)
// 2gb;00000001
// 2gs;01000000(Shift the bit 6 times to the left.)
// 2ch;01000000(Compare 1ch and 2gs with |.)
// 3gb;00000001
// 3gs;00100000(Shift the bit 5 times to the left.)
// 3ch;01100000(Compare 2ch and 3gs with |.)
// 4gb;00000000
// 4gs;00000000(Shift the bit 4 times to the left.)
// 4ch;01100000(Compare 3ch and 4gs with |.)
// 5gb;00000000
// 5gs;00000000(Shift the bit 3 times to the left.)
// 5ch;01100000(Compare 4ch and 5gs with |.)
// 6gb;00000000
// 6gs;00000000(Shift the bit 2 times to the left.)
// 6ch;01100000(Compare 5ch and 6gs with |.)
// 7gb;00000000
// 7gs;00000000(Shift the bit 1 times to the left.)
// 7ch;01100000(Compare 6ch and 7gs with |.)
// 8gb;00000001
// 8gs;00000001(Shift the bit 0 times to the left.)
// 8ch;01100001(Compare 7ch and 8gs with |.)
