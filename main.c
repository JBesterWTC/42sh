/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:07:40 by jbester           #+#    #+#             */
/*   Updated: 2016/09/01 10:27:09 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ft_check(char *line, char **nenv)
{
	int	check;

	check = 0;
	ft_skip(&line);
	if (*line == '\0')
		return (1);
	if (ft_strncmp(line, "exit", 4) == 0)
		exit(0);
	if (ft_strncmp(line, "env", 3) == 0)
	{
		ft_display_env(nenv);
		return (1);
	}
	if (ft_strncmp(line, "echo", 4) == 0)
	{
		ft_echo(line, nenv);
		return (1);
	}
	if (line[0] == '/'  || line[0] == '.')
	{
		if (ft_straight_exec(line, nenv) != 1)
			return (0);
		return (1);
	}
	if (ft_strncmp(line, "pwd", 3) == 0)
	{
		get_pwd();
		return (1);
	}
	check = ft_path_check(line, nenv);
	if (check == 1)
		return (1);
	else if (check == 0)
		return (0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	char			**nenv;
	char			*line;

	(void)argc;
	(void)argv;
	nenv = ft_cpy_env(env, 0);
	ft_putstr("Shell> ");
	while ((ft_get_next_line(0, &line)) > 0)
	{
		if (ft_check(line, nenv) == 0)
		{
			ft_putstr("42sh does not recognise the command: ");
			ft_putendl(line);
		}
		ft_putstr("Shell> ");
	}
	return (0);
}
