#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	if ((*free_fct) == 0)
		return ;
	while (begin_list)
	{
		free_fct(begin_list->data);
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
}
