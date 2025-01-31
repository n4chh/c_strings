#include "libstrings.h"

t_string	*split(t_string string, t_string delimitator)
{
	size_t		w;
	size_t		list_size;
	t_string	str;
	t_string	*list;

	w = 0;
	list_size = wordcount(string, delimitator);
	list = malloc(sizeof(t_string) * (list_size + 1));
	if (list == NULL)
		return (NULL);
	str = str_cpy(string);
	if (str == NULL)
		return (NULL);
	while (w++ < list_size)
	{
		findword(str, delimitator);
		list[w - 1] = str_cpy(str);
		if (list[w - 1] == NULL)
			return (dtor(&str), rclearlist(list, --w), NULL);
		str->start = str->end;
		str->end = string->end;
	}
	list[w - 1] = NULL;
	dtor(&str);
	return (list);
}

void	printlist(t_string *string, t_string separator)
{
	size_t	i;

	if (string == NULL)
		return ;
	i = 0;
	while (string[i] != NULL)
	{
		print(string[i]);
		i++;
		if (string[i] != NULL)
			print(separator);
	}
}
