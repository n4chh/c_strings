#include "libstrings.h"

static int checkranges(t_string string, size_t splits, size_t *positions) {
    size_t i;

    i = 0;
    if (splits == 0)
        return (1);
    while (i < splits) {
        if (positions == NULL || string->end < positions[i])
            return (0);
        i++;
    }
    if (i != 0)
        i--;
    if (positions && string->end < positions[i])
        return (0);
    return (1);
}

t_string *nsplit(t_string string, size_t splits, size_t *position) {
    size_t w;
    t_string *list;
    t_string str;

    w = 0;
    if (!checkranges(string, splits, position))
        return (NULL);
    str = str_cpy(string);
    if (str == NULL)
        return (NULL);
    splits++;
    list = malloc(sizeof(t_string) * (splits + 1));
    if (list == NULL)
        return (dtor(&str), NULL);
    while (w++ < splits) {
        if (w == splits)
            str->end = string->end;
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

t_string lstostr(t_string *list) {
    t_string str;
    size_t length;
    size_t i;
    size_t n;

    if (list == NULL)
        return (NULL);
    n = 0;
    length = 0;
    ctor(&str, NULL);
    if (str == NULL)
        return (str);
    while (list[n])
        length += len(list[n++]);
    n = 0;
    str->data = malloc(length + 1);
    str->data_len = length;
    while (list[n++]) {
        i = list[n - 1]->start;
        while (i < list[n - 1]->end)
            str->data[str->end++] = list[n - 1]->data[i++];
    }
    str->data[length] = 0;
    return (str);
}

// t_string	*pos_split(t_string	string, size_t position[][2])
// {
// 	t_string	*list;
// 	t_string	cursor;
// 	size_t		size;
//
// 	size = 0;
// 	if (string == NULL || string->data == NULL || position  == NULL
// 		|| *position == NULL)
// 		return (NULL);
// 	while (position[size] != NULL)
// 		size++;
// 	cursor = str_cpy(string);
// 	list = (t_string *) malloc(sizeof(t_string) * (size + 1));
// 	if (list == NULL || cursor == NULL)
// 		return (NULL);
// 	size = 0;
// 	while (position[size])
// 	{
// 		cursor->start = position[size][0];
// 		cursor->end = position[size][1];
// 		list[size] = str_cpy(cursor);
// 		if (list[size] == NULL)
// 			return (dtor(&cursor), rclearlist(list, --size), NULL);
// 		size++;
// 	}
// 	return (list[size] = NULL, dtor(&cursor), list);
// }
