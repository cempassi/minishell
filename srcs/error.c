/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:25:23 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/04 23:40:27 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_error(t_prgm *glob)
{
	glob->errstr[0] = "minishell";
	glob->errstr[1] = "command not found";
	glob->errstr[2] = "System Failure on malloc";
	glob->errstr[3] = "System Failure on Open";
	glob->errstr[4] = "System Failure on Close";
	glob->errstr[5] = "System Failure on Read";
	glob->errstr[6] = "System Failure on Getpwuid";
	glob->errstr[7] = "Unclosed comma";
	glob->errstr[8] = "Cd takes only one argument";
	glob->errstr[9] = "Not enough Argumends";
	glob->errstr[10] = "Invalid path";
	glob->errstr[11] = "Too many arguments";
	glob->errstr[12] = "Is not a directory";
	glob->errstr[13] = "Wrong number of Arguments";
	glob->errstr[14] = "No arguments to unset";
	glob->errstr[15] = "Null argument passed";
}

void	error_manager(t_prgm *glob)
{
	const char	**errstr;
	int			errno;
	int			id;

	errno = ft_abs(glob->error);
	glob->error = 0;
	id = glob->tab.id;
	errstr = glob->errstr;
	if (errno == 1)
		ft_dprintf(2, "%s: %s: %s\n", *errstr, errstr[errno], glob->tab.av[id]);
	else if (errno >= 2 && errno <= 6)
	{
		ft_dprintf(2, "%s: %s\n", *errstr, errstr[errno]);
		ms_exit(glob);
	}
	else if (errno >= 7 && errno <= 15)
		ft_dprintf(2, "%s: %s\n", *errstr, errstr[errno]);
	return ;
}
