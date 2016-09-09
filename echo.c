/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:21:54 by jbester           #+#    #+#             */
/*   Updated: 2016/08/23 11:51:47 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ft_echo(char *line, char **env)
{
	int		i;
	int		c;
	int		check;
	char	**new;
	char	*str;
	char	*bslash;

	i = 0;
	c = 1;
	str = 0;
	bslash = 0;
	check = 0;
	new = ft_strsplit(line, ' ');
	if (!new)
	{
		ft_putchar('\n');
		return (0);
	}
	while (new[c] != NULL)
	{
		if (ft_strcmp(new[c], "\\") == 0 && !(new[c + 1]))
		{
			bslash = ft_bslash_wait(new[c]);
			break ;
		}
		c++;
	}
	c = 1;
	while (new[c] != NULL)
	{
		while (new[c][i] != '\0')
		{
			if (new[c][i] == '$' && new[c][i - 1] != '\\')
			{
				ft_env_print(new[c], env);
				ft_putchar('\n');
				return (0);
			}
			if ((new[c][i] == '"' || new[c][i] == 39) && !check)
			{
				check = 1;
				str = ft_solve(new[c], i);
				i++;
			}
			i++;
		}
		ft_echo_output(new[c]);
		if (ft_strcmp(new[c], "\\") != 0)
			ft_putchar(' ');
		c++;
	}
	if (str)
	{
		ft_putchar('\n');
		ft_echo_output(str);
	}
	else if (bslash)
		ft_echo_output(bslash);
	ft_putchar('\n');
	return (0);
}

void	ft_env_print(char *var, char **env)
{
	int		c;
	char	**new;

	c = 0;
	var = ft_strsub(var, 1, (ft_strlen(var) - 2));
	while (env[c] != NULL)
	{
		if (ft_strncmp(env[c], var, ft_strlen(var)) == 0)
		{
			new = ft_strsplit(env[c], '=');
			ft_putstr(new[1]);
			return ;
		}
		c++;
	}
}
