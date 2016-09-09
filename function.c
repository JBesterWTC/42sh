/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:40:46 by jbester           #+#    #+#             */
/*   Updated: 2016/08/22 09:59:34 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_skip(char **s)
{
	while (*s && (**s == ' ' || **s == '\t' || **s == '\n'))
		(*s)++;
}

char	**ft_update_env(char **env, char *name, char *value)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(name) - 1;
	new = ft_strjoin(name, "=");
	new = ft_strjoin(new, value);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(new);
			return (env);
		}
		i++;
	}
	return (env);
}

void	ft_change_home(char **env)
{
	int		i;
	char	**new;

	i = 0;
	new = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME", 4) == 0)
		{
			new = ft_strsplit(env[i], '=');
			chdir(new[1]);
			return ;
		}
		i++;
	}
}

char	*ft_solve(char *str, int count)
{
	int	dquote;
	int	quote;

	dquote = 0;
	quote = 0;
	while (str[count])
	{
		if (str[count] == '"')
			dquote++;
		if (str[count] == 39)
			quote++;
		count++;
	}
	if (dquote % 2 == 0 && quote % 2 == 0)
		return (0);
	else if (dquote % 2 != 0)
		str = ft_dquote_wait(str);
	else if (quote % 2 != 0)
		str = ft_quote_wait(str);
	return (str);
}

void	ft_echo_output(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == 39 || str[i] == '\\')
			i++;
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
