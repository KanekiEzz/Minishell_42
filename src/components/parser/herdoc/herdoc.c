/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:43:44 by yaajagro          #+#    #+#             */
/*   Updated: 2025/04/19 18:43:56 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/parser.h"

void	herdoc_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_malloc(-1);
		close(3);
		exit(130);
	}
}

int	only_space(char *s)
{
	if ((s[0] == ':' && ft_isspace(s[1])) || (s[0] == ':' && !s[1]))
		return (1);
	while (*s)
	{
		if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

char	*remove_qoats(char *s)
{
	char	*result;
	int		i;
	int		j;
	bool	in_single_quotes;
	bool	in_double_quotes;

	if (!s)
		return (NULL);
	result = ft_malloc(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	in_single_quotes = false;
	in_double_quotes = false;
	while (s[i])
	{
		if (s[i] == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		else if (s[i] == '\"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		else
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

t_cmd	*new_cmd_hered(char **val)
{
	t_cmd	*ret;

	ret = ft_malloc(sizeof(t_cmd));
	ret->cmd = val;
	ret->pip_infront = 0;
	ret->type = COMMAND;
	ret->next = NULL;
	ret->value = NULL;
	return (ret);
}

char	*herdoc(t_env *env, t_cmd *commnd, t_cmd **head, char *exit)
{
	char	*name;
	bool	qoated;
	char	**arg;

	qoated = will_expanded(exit);
	set_space_zero_qoats(exit);
	arg = ft_split_adv(exit);
	if (!arg)
		return (ft_strdup(""));
	set_zero_space(arg);
	exit = remove_qoats(arg[0]);
	if (commnd)
		commnd->cmd = join_args_adv(commnd->cmd, arg);
	else if (arg && *(arg + 1))
		add_to_cmd(head, new_cmd_hered(arg + 1));
	name = get_herdoc_fd(env, exit, qoated, env->data->exe_state);
	return (name);
}
