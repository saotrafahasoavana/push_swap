/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:40:17 by saandria          #+#    #+#             */
/*   Updated: 2024/05/17 20:33:53 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_split(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

static void	if_error(char **args)
{
	if (args[0] == 0)
	{
		free_split(args);
		ft_error();
		exit (1);
	}
	if (!check_input(args))
	{
		free_split(args);
		ft_error();
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	char	*arg;

	if (argc == 1)
		return (0);
	arg = get_input(argv);
	args = ft_split(arg, ' ');
	free(arg);
	if_error(args);
	a = create_stack(args, 0);
	free_split(args);
	b = NULL;
	if (is_sorted(a) == 1)
	{
		free_stack(&a);
		return (0);
	}
	sort(a, b);
	return (0);
}
