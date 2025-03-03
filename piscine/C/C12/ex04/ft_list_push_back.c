#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = ft_create_elem(data);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}
