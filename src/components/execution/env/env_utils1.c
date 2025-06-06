/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:18:58 by iezzam            #+#    #+#             */
/*   Updated: 2025/04/25 10:50:35 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

int	ft_env_add(t_env **env, char *key, char *value, int visible)
{
	t_env	*new;
	t_env	*last;

	value = ft_strdup(value);
	new = ft_malloc(sizeof(t_env));
	new->key = key;
	new->value = value;
	new->next = NULL;
	new->visible = visible;
	last = *env;
	if (!last)
		return (*env = new, 0);
	if (ft_strcmp(new->key, last->key) < 0)
		return (new->next = *env, *env = new, 0);
	while (last && last->next)
	{
		if (ft_strcmp(new->key, last->next->key) < 0)
			return (new->next = last->next, last->next = new, 0);
		last = last->next;
	}
	last->next = new;
	return (0);
}

void	ft_env_clear(t_env **env)
{
	t_env	*cur_node;
	t_env	*nxt_node;

	if (!env)
		return ;
	cur_node = *env;
	while (cur_node)
	{
		nxt_node = cur_node->next;
		cur_node = nxt_node;
	}
	*env = NULL;
}

void	ft_env_delete(t_env **env, char *key)
{
	t_env	*prev;
	t_env	*cur;

	if (!env || !(*env))
		return ;
	prev = *env;
	if (!ft_strcmp(key, prev->key))
	{
		(*env) = prev->next;
		return ;
	}
	cur = prev->next;
	while (cur)
	{
		if (!ft_strcmp(key, cur->key))
		{
			prev->next = cur->next;
			return ;
		}
		cur = cur->next;
		prev = prev->next;
	}
}

t_env	*ft_env_duplicate(t_env *env)
{
	t_env	*env_dup;

	env_dup = NULL;
	while (env)
	{
		ft_env_add(&env_dup, ft_strdup(env->key),
			ft_strdup(env->value), env->visible);
		env = env->next;
	}
	return (env_dup);
}
