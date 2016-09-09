/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:00:34 by jbester           #+#    #+#             */
/*   Updated: 2016/08/22 10:20:06 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_dquote_wait()
{
	char	*line;
	char	*str;
	int		check;
	
	line = 0;
	str = 0;
	check = 0;
	ft_putstr("dquote> ");
	while ((ft_get_next_line(0, &line)) > 0)
	{
		if (check == 0)
		{
			str = ft_strdup(line);
			str = ft_strjoin(str, "\n");
		}
		if (ft_strchr(line, '"'))
			return (str);
		if (check > 0)
		{
			str = ft_strjoin(str, line);
			str = ft_strjoin(str, "\n");
		}			
		check++;
		ft_putstr("dquote> ");
	}
	return (str);
}

char	*ft_quote_wait(char *str)
{
	char	*line;

	line = 0;
	ft_putstr("quote> ");
	while ((ft_get_next_line(0, &line)) > 0)
	{
		if (*line == 39)
			return (str);
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, "\n");
		ft_putstr("quote> ");
	}
	return (0);
}

char	*ft_bslash_wait(char *str)
{
	char	*line;

	line = 0;
	ft_putstr("bslash> ");
	while (ft_get_next_line(0, &line) != 1)
	{
		if (!line)
			return (str);
		str = ft_strjoin(str, line);
	}
	return (line);
}
