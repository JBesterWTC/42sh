/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:20:52 by jbester           #+#    #+#             */
/*   Updated: 2016/08/17 13:42:00 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	get_pwd(void)
{
	char	buf[4096];

	getcwd(buf, 4096);
	ft_putendl(buf);
}

int		change_dir(char *line, char **env)
{
	if (ft_strcmp(line, "cd") != 0 && ft_strcmp(line, "cd ") != 0)
	{
		if (ft_normal_change(line, env) != 0)
			return (1);
		else
			return (0);
	}
	else
	{
		env = ft_set_oldpwd(env);
		ft_change_home(env);
		env = ft_set_pwd(env);
		return (0);
	}
	return (1);
}

int		check_dir(char *dir)
{
	if (access(dir, X_OK) == 0)
		return (0);
	else
	{
		ft_putstr("Invalid file or directory: ");
		ft_putendl(dir);
	}
	return (1);
}

char	*ft_cd_back(char **env)
{
	int		i;
	char	**dir;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			dir = ft_strsplit(env[i], '=');
			ft_putendl(dir[1]);
			return (dir[1]);
		}
		i++;
	}
	return (0);
}

int		ft_normal_change(char *line, char **env)
{
	char	**info;

	info = ft_strsplit(line, ' ');
	if (ft_strlen(info[0]) > 2)
	{
		ft_putstr("42sh does not recognise the command: ");
		ft_putendl(line);
		return (1);
	}
	else if (info[1][0] == '~' || (!info[1]))
	{
		env = ft_set_oldpwd(env);
		ft_change_home(env);
		env = ft_set_pwd(env);
		return (0);
	}
	else if (info[1][0] == '-')
		info[1] = ft_cd_back(env);
	if (check_dir(info[1]) == 0)
	{
		env = ft_set_oldpwd(env);
		chdir(info[1]);
		env = ft_set_pwd(env);
		return (0);
	}
	return (1);
}
