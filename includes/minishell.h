/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:01:31 by aharrass          #+#    #+#             */
/*   Updated: 2023/03/01 05:23:11 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_envp
{
	char			*var;
	char			*value;
	struct s_envp	*next;
}					t_env;

typedef struct s_export
{
	char			*var;
	char			*value;
	struct s_export	*next;
}					t_export;

struct				s_env
{
	int				status;
	t_env			*env;
	t_export		*export;
};

typedef struct s_var
{
	int				**fd;
}					t_var;

typedef struct s_cmd
{
	char			**herdoc;
	int				in;
	int				out;
	int				err;
	char			*cmd;
	char			**args;
	struct s_cmd	*next;
}					t_cmd;

struct s_env		g_env;

//extern struct s_env	g_env;

void				ft_print(void);
void				ft_pwd(void);
void				ft_cd(char *dir);
void				ft_env(void);
t_env				*ft_lstnew(char *var);
t_env				*ft_lstadd_back(t_env **env, t_env *new);
void				ft_export(char *var);
t_export			*ft_lstnew_export(char *var);
void				ft_lstadd_back_export(t_export **export, t_export *new);
#endif
