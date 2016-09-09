/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 07:54:04 by jbester           #+#    #+#             */
/*   Updated: 2016/09/01 09:59:13 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_path_check(char *line, char **env)
{
	char	**path;
	char	**arg;

	path = ft_path_grab(env);
	arg = ft_arg_grab(line);
	if (ft_execute(path, arg, env) == 1)
		return (1);
	/*else
	{
		free(path);
		free(arg);
	}*/
	return (0);
}

char	**ft_path_grab(char **env)
{
	int		i;
	char	**var;
	char	**paths;

	i = 0;
	var = 0;
	paths = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			var = ft_strsplit(env[i], '=');
			paths = ft_strsplit(var[1], ':');
		}
		i++;
	}
	return (paths);
}

char	**ft_arg_grab(char *line)
{
	char	**args;

	args = ft_strsplit(line, ' ');
	return (args);
}

int		ft_check_exec(char *path, char **args, char **env)
{
	char	*file;

	file = NULL;
	file = ft_strcat(path, "/");
	file = ft_strcat(path, args[0]);
	if (access(file, X_OK) != -1)
	{
		ft_putendl("Reached");
		execve(file, args, &env[0]);
		return(1);
	}
	return (0);
}

int	ft_execute(char **paths, char **args, char **env)
{
	pid_t			child;
	int				i;
	int				end;

	i = 0;
	end = 0;
	child = fork();
	if (child == 0)
	{
		while (paths[i] != NULL)
		{
			if (ft_check_exec(paths[i], args, env) == 1)
				exit(0);
			i++;
		}
		exit(1);
	}
	else
	{
		wait(&end);
		if (WEXITSTATUS(end) == 0)
			return (1);
	}
	return (0);
}

int		ft_straight_exec(char *line, char **env)
{
	char	**new;
	char	*exec;
	pid_t	child;
	int		status;

	new = ft_strsplit(line, ' ');
	exec = ft_strdup(new[0]);
	free(new[0]);
	child = fork();
	status = 0;
	if (child == 0)
	{
		if (access(exec, X_OK) == 0)
		{
			execve(exec, new, &env[0]);
			exit(0);
		}
		exit(1);
	}
	else
	{
		wait(&status);
		if (WEXITSTATUS(status) == 0)
			return (1);
	}
	return (0);
}
