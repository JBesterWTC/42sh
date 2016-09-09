/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 09:51:55 by jbester           #+#    #+#             */
/*   Updated: 2016/09/01 08:17:04 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINI_H__
# define __MINI_H__
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
//# include <curses.h>
//# include <term.h>
# include <sys/ioctl.h>
# include <termios.h>
# include "libft.h"

int		ft_check(char *line, char **nenv);
int		ft_env_size(char **env);
char	**ft_cpy_env(char **env, int extra);
void	ft_display_env(char **env);
void	ft_skip(char **s);
char	**ft_setenv(char **env, char *line);
char	**ft_unsetenv(char **env, char *line);
char	**ft_update_env(char **env, char *name, char *value);
void	get_pwd(void);
int		change_dir(char *line, char **env);
int		check_dir(char *dir);
char	**ft_set_oldpwd(char **env);
char	**ft_set_pwd(char **env);
char	*ft_cd_back(char **env);
int		ft_path_check(char *line, char **env);
char	**ft_path_grab(char **env);
char	**ft_arg_grab(char *line);
int		ft_check_exec(char *path, char **args, char **env);
int		ft_execute(char **paths, char **args, char **env);
int		ft_straight_exec(char *linei, char **env);
int		ft_echo(char *line, char **env);
void	ft_env_print(char *var, char **env);
int		ft_normal_change(char *line, char **env);
void	ft_change_home(char **env);
char	*ft_solve(char *str, int count);
char	*ft_dquote_wait();
char	*ft_quote_wait(char *str);
void	ft_echo_output(char *str);
char	*ft_bslash_wait(char *str);

#endif
