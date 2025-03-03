#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*new_elem;

	i = 1;
	if (size <= 0 || strs == NULL)
		return (NULL);
	list = ft_create_elem(strs[0]);
	while (i < size && strs[i])
	{
		new_elem = ft_create_elem(strs[i]);
		new_elem->next = list;
		list = new_elem;
		i++;
	}
	return (list);
}
