#include "libstrings.h"

t_string *p_split(t_string string, const char *delimitator) {
    size_t w;
    size_t list_size;
    t_string str;
    t_string *list;

    w = 0;
    list_size = wordcount(string, delimitator);
    list = malloc(sizeof(t_string) * (list_size + 1));
    if (list == NULL)
        return (NULL);
    str = str_cpy(string);
    if (str == NULL)
        return (NULL);
    while (w++ < list_size) {
        p_findword(str, delimitator);
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

t_string *charlstostrls(char **list) {
    t_string *new_list;
    size_t i;

    if (list == NULL || *list == NULL)
        return (NULL);
    i = 0;
    while (list[i] != NULL)
        i++;
    new_list = malloc(sizeof(t_string) * i + 1);
	if (new_list)
		return (NULL);
	i = 0;
    while (list[i] != NULL) {
        ctor(&new_list[i], p_str_cpy(list[i]));
        if (new_list[i] == NULL)
            return (rclearlist(new_list, i), NULL);
        i++;
    }
	new_list[i] = NULL;
    return (new_list);
}

char **strlstocharls(t_string *list) {
    size_t list_size;
    char **strlist;

    if (list == NULL)
        return (NULL);
    list_size = 0;
    while (list[list_size] != NULL)
        list_size++;
    strlist = malloc(sizeof(char *) * (list_size + 1));
    if (strlist == NULL)
        return (NULL);
    list_size = 0;
    while (list[list_size] != NULL) {
        strlist[list_size] = list[list_size]->data;
        list_size++;
    }
    strlist[list_size] = NULL;
    return (strlist);
}
