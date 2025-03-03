#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
