/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcha <matcha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:55:34 by anovikav          #+#    #+#             */
/*   Updated: 2022/11/22 14:29:42 by matcha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_size(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] != '\0')
		len = 1;
	else
		len = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] == ' ')
			len ++;
		i++;
	}
	return (len);
}

static void	choose_sort(t_stack *a, t_stack *b)
{
	if (check_order(a) == FAIL)
	{
		if (a->size == 2 && check_order(a) == FAIL)
			swap(a);
		else if (a->size == 3)
			three_sort(a);
		else if (a->size == 5)
			five_sort(a, b);
		else
			ft_raddix(a, b);
	}
	display_stack(a, b);
	free_all(a, b);
}

static void	error_before_a(char **tab, int max, int ac)
{
	int		i;

	i = 0;
	if (check_digit(tab) == FAIL)
	{
		if (ac == 2)
			free_tab(tab);
		exit(EXIT_FAILURE);
	}
	while (i < max)
	{
		if (check_minimax(tab[i]) == FAIL)
		{
			if (ac == 2)
				free_tab(tab);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static t_stack	get_a(char **tab, int max, int ac)
{
	t_stack	a;

	error_before_a(tab, max, ac);
	a = init_stack(tab, max, max, 'a');
	if (!a.array)
		return (a);
	if (ac == 2)
		free_tab(tab);
	if (check_repetition(a.array, a.size) == FAIL)
	{
		free_all(&a, NULL);
		exit(EXIT_FAILURE);
	}
	get_index(&a);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**tab;
	int		max;

	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] != 0)
	{
		max = max_size(av[1]);
		tab = ft_split(av[1], ' ');
		if (!tab)
			exit(EXIT_FAILURE);
	}
	else
	{
		tab = av + 1;
		max = ac - 1;
	}
	a = get_a(tab, max, ac);
	b = init_stack(NULL, 0, a.size, 'b');
	if (a.array == NULL || b.array == NULL)
		free_all(&a, &b);
	choose_sort(&a, &b);
	return (0);
}
