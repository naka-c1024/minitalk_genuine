/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:11:27 by ynakashi          #+#    #+#             */
/*   Updated: 2021/10/15 09:01:20 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <limits.h>
# include "libft/libft.h"

# define COLOR_R	"\033[41m"
# define COLOR_B	"\033[44m"
# define COLOR_OFF	"\033[m"

typedef enum e_flag
{
	ERROR = -1,
	OFF,
	ON,
}			t_flag;

extern unsigned int	g_flag;
// volatile sig_atomic_t	g_flag;

#endif
