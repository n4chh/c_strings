#include "libstrings.h"

long int findchar(t_string string, const char c) {
    long int pos;

    if (string == NULL || string->data == NULL)
        return (-1);
    pos = string->start;
    while ((size_t)pos + string->start < string->end) {
        if (get(string, pos) == c)
            break;
        pos++;
    };
    if ((size_t)pos == string->end)
        pos = -1;
    return (pos);
}

long int p_findchar(const char *string, const char c) {
    long int pos;

    if (string == NULL)
        return (-1);
    pos = 0;
    while (string[pos] != 0) {
        if (string[pos] == c)
            break;
        pos++;
    }
    if (string[pos] == 0)
        pos = -1;
    return (pos);
}
