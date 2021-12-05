/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:15:21 by ynakashi          #+#    #+#             */
/*   Updated: 2021/10/19 11:07:30 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_kill(int	flag, pid_t pid)
{
	if (flag == ON)
	{
		if (kill(pid, SIGUSR1) == ERROR)
		{
			ft_putendl_fd(COLOR_R"KILL ERROR"COLOR_OFF, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == ERROR)
		{
			ft_putendl_fd(COLOR_R"KILL ERROR"COLOR_OFF, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
}

static void	send_signal(const pid_t pid, char *str)
{
	uint8_t	eight_bit;
	int		shift_size;
	size_t	i;

	i = 0;
	while (str[i])
	{
		eight_bit = (int8_t)str[i++];
		shift_size = 7;
		while (shift_size > -1)
		{
			if (((eight_bit >> shift_size) & 1) == ON)
				ft_kill(ON, pid);
			else
				ft_kill(OFF, pid);
			shift_size--;
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putendl_fd(COLOR_B"invalid argument"COLOR_OFF, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid == 0 || pid == -1 || kill(pid, 0) == ERROR)
	{
		ft_putendl_fd(COLOR_R"BAD PID"COLOR_OFF, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	send_signal(pid, argv[2]);
	return (0);
}
