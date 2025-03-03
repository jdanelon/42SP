#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*list;

	i = 0;
	list = begin_list;
	while (i < nbr && list)
	{
		if (list == 0)
			return (0);
		list = list->next;
		i++;
	}
	return (list);
}
