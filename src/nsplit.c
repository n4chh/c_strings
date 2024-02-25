#include "libstrings.h"

// static int wordcount(t_string   this, char  *delimitator)

static int	checkranges(t_string this, size_t splits, size_t *positions)
{
	size_t i;

	i = 0;
	while (i < splits)
	{
		if (this->end < positions[i])
			return (0);
		i++;
	}
	i--;
	if (this->end < positions[i])
		return (0);
	return (1);
}
static void	rclearlist(t_string *this, size_t	size)
{
	while (size-- > 0)
		dtor(&this[size]);
	free(this);
	this = NULL;
}

t_string	*nsplit(t_string this, size_t splits, size_t *position)
{
	size_t		w;
	t_string	*list;
	t_string	str;

	w = 0;
	str = str_cpy(this);
	if (!str || !checkranges(this, splits, position))
		return (NULL);
	splits++;
	list = malloc(sizeof(t_string) * (splits + 1));
	if (!list)
		return (dtor(&str), NULL);
	while (w++ < splits)
	{
		if (w == splits)
			str->end = this->end;
		else
			str->end = position[w - 1];
		list[w - 1] = str_cpy(str);
		if (list[w - 1] == NULL)
			return (dtor(&str), rclearlist(list, --w), NULL);
		str->start = str->end + 1;
	}
	list[w - 1] = NULL;
	return (dtor(&str), list);
}
