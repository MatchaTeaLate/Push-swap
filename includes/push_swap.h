/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:27:25 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 07:16:45 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "libft/ft_printf/ft_printf.h"

# define FAIL 1
# define SUCCESS 0

typedef struct s_stack
{
	int		*array;
	int		*index;
	int		size;
	char	name;
}				t_stack;

t_stack	init_stack(char **input, int len, int size_max, char name);

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *stack_1, t_stack *stack_2);

void	get_index(t_stack *stack);
void	shortcut(t_stack *stack, int max_size);

void	free_tab(char **str);
void	free_stack(t_stack *stack);
void	free_all(t_stack *a, t_stack *b);

void	three_sort(t_stack	*a);
void	five_sort(t_stack *a, t_stack *b);
void	ft_raddix(t_stack *a, t_stack *b);

int		check_digit(char **str);
int		check_repetition(int *list, int size);
int		check_order(t_stack	*stack);
int		check_true_order(t_stack *stack);
int		check_minimax(char *str);

#endif
