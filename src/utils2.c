#include "libstrings.h"

size_t p_wordcount(t_string string, const char *delimitator) {
    size_t words;
    size_t init_start;
    t_string next;

    words = 0;
    next = str_cpy(string);
    if (next == NULL)
        return (0);
    init_start = string->start;
    while (next->start < next->end) {
        p_findword(next, delimitator);
        words++;
        next->start = next->end;
        next->end = string->end;
    }
    string->start = init_start;
    dtor(&next);
    return (words);
}

size_t	wordcount(t_string string, t_string delimitator)
{
	size_t		words;
	size_t		init_start;
	t_string	next;

	words = 0;
	next = str_cpy(string);
	if (next == NULL)
		return (0);
	init_start = string->start;
	while (next->start < next->end)
	{
		findword(next, delimitator);
		words++;
		next->start = next->end;
		next->end = string->end;
	}
	string->start = init_start;
	dtor(&next);
	return (words);
}

void	rclearlist(t_string *string, size_t	size)
{
	while (size-- > 0)
		dtor(&string[size]);
	free(string);
	string = NULL;
}

