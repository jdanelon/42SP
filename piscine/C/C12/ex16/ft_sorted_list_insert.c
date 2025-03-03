#include "ft_list.h"

static void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = ft_create_elem(data);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	if ((*cmp) == 0)
		return ;
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, (*cmp));
}
