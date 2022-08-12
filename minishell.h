/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:36 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/12 21:07:46 by ibenmain         ###   ########.fr       */
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

typedef enum s_enum
{
	WORD,
	PIPE,
	OUT_RED,
	IN_RED,
	D_QOUT,
	S_QOUT,
}	t_enum;

typedef struct s_env{
	char			*var;
	char			*val;
	struct s_env	*next;
}	t_env;

typedef struct s_tok{
	char			*value;
	int				type;
	struct s_tok	*next;
}	t_tok;

typedef struct s_all{
	t_env	*env;
	t_tok	*rid;
}	t_all;

void	desplay_shell(char **data);
t_env	*init_env(char **env);
t_env	*ft_creat_node(char *data);
char	*ft_val(char *data);
char	*ft_key(char *data);
int		ft_index_key(char *data);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_env **alst, t_env *new);
void	ft_add_back(t_tok **alst, t_tok *new);
size_t	ft_strlen(char *s);
void	init_sig(void);
void	check_line(char *line, t_env *env);
int		get_index(char *str);
t_tok	*ft_tokens(char *str);
void	ft_add_back(t_tok **alst, t_tok *new);
t_tok	*get_rid(char *str);
t_tok	*replace_env(t_tok *lst, t_env *env);
int		ft_strncmp(char *str1, int i, char *str2);
int		ft_strcmp(char *str1, char *str2);
int		check_space(char *str, int i);
int		ft_get_great(char *str, int i, t_tok **head);
int		ft_get_less(char *str, int i, t_tok **head);
int		ft_get_pipe(char *str, int i, t_tok **head);
int		ft_get_double(char *str, int i, t_tok **head);
int		ft_get_single(char *str, int i, t_tok **head);
int		ft_get_word(char *str, int i, t_tok **head);
t_tok	*creat_token(int start, int len, char *str, int typ);
char	*ft_check_qout(char *str);
char	*ft_check_all_error(char *str);
char	*ft_strtrim(char *s1, char *set);

#endif