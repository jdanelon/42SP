#include "ft_list.h"

static void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *tmp;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	tmp = *begin_list1;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = begin_list2;
}

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*it;
	void	*tmp;

	if ((*cmp) == 0 || *begin_list == 0)
		return ;
	it = *begin_list;
	while (it->next)
	{
		if ((*cmp)(it->data, it->next->data) > 0)
		{
			tmp = it->data;
			it->data = it->next->data;
			it->next->data = tmp;
			it = *begin_list;
		}
		else
			it = it->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	if ((*cmp) == 0)
		return ;
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
