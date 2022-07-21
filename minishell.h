/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:36 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/21 23:36:51 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <ctype.h>
# include <errno.h>
# include <dirent.h>
# include "readline/readline.h"
# include "readline/history.h"

typedef struct s_env{
	char			*var;
	char			*val;
	struct s_env	*next;
}	t_env;

typedef struct s_all{
	t_env	*env;
}	t_all;

void	desplay_shell(char **data);
t_env	*init_env(char **env);
t_env	*ft_creat_node(char *data);
char	*ft_val(char *data);
char	*ft_key(char *data);
int		ft_index_key(char *data);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_env **alst, t_env *new);
size_t	ft_strlen(char *s);
void	init_sig(void);
#endif