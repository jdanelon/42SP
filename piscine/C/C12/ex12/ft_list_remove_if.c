#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*it;
	t_list	*previous;
	t_list	*to_remove;

	it = *begin_list;
	previous = 0;
	to_remove = 0;
	if ((*cmp) == 0 || (*free_fct) == 0)
		return ;
	while (it)
	{
		if ((*cmp)(it->data, data_ref) == 0)
		{
			if (it == *begin_list)
				*begin_list = it->next;
			else
				previous->next = it->next;
			to_remove = it;
			it = it->next;
			(*free_fct)(to_remove->data);
			free(to_remove);
		}
		else
		{
			previous = it;
			it = it->next;
		}
	}
}
