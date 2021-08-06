#include "push_swap.h"
#include <stdio.h>

t_stack	*init_stack()
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	ret->first = NULL;
	return (ret);
}

t_list	*parse_arg(int ac, char **av)
{
	int	i;
	t_list	*start;

	start = ft_lstnew(ft_atoi(av[ac - 1]));
	i = ac - 2;
	while (i > 0)
	{
		ft_lstadd_front(&start, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
	return (start);
}

void	ft_rotate(t_stack *src)
{
	t_list	*tmp;

	tmp = src->first;
	src->first = src->first->next;
	ft_lstadd_back(&src->first, tmp);
}

void	ft_reverse_rotate(t_stack *src)
{
	t_list	*tmp;

	tmp = src->first;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&src->first, ft_lstlast(src->first));
	tmp->next = NULL;
}

void	ft_swap(t_stack	*src)
{
	t_list	*tmp0;
	t_list	*tmp1;

	if (src->first == NULL || src->first->next == NULL)
		return ;
	tmp0 = src->first->next->next;
	tmp1 = src->first->next;
	src->first->next->next = src->first;
	src->first->next = tmp0;
	src->first = tmp1;
}

void	ft_push(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	if (src->first == NULL)
		return ;
	tmp = src->first->next;
	ft_lstadd_front(&dst->first, src->first);
	src->first = tmp;
}

void	printstacks(t_stack *a, t_stack *b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = a->first;
	tmpb = b->first;;
	while (tmpa != NULL && tmpb != NULL)
	{
		printf("| %d |     | %d |\n", tmpa->content, tmpb->content);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	while (tmpa != NULL)
	{
		printf("| %d |     |   |\n", tmpa->content);
		tmpa = tmpa->next;
	}
	while (tmpb != NULL)
	{
		printf("|   |     | %d |\n", tmpb->content);
		tmpb = tmpb->next;
	}
	printf("---------------\n| A |     | B |\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	b = init_stack();
	a->first = parse_arg(ac, av);
	ft_rotate(a);
	printstacks(a, b);
	return (0);
}
