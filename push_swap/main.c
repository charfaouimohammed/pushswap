/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mocharfa <mocharfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:35:25 by mocharfa          #+#    #+#             */
/*   Updated: 2022/06/26 20:30:15 by mocharfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	has_min = 0;
	min = NULL;
	head = *stack;

	if (head)
	{
		while (head->next != NULL)
		{
			if ((head->index == -1 && !has_min) || (head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head->next != NULL)
	{
		head->index = index++;
		head = get_next_min(stack);
        head = head->next;
	}
    // printf("helllo\n");
    // exit(1);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (countlist (*stack_a) <= 5)
		short_sort(stack_a, stack_b);
	else
		bigsort(stack_a, stack_b);
}

void	initstatick(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;
  
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_addback(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_checkargs(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initstatick(stack_a, argc, argv);
	if (is_sorted (stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
