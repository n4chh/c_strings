#include "libstrings.h"

t_string str_cpy(t_string string) {
    char *str;
    size_t i;
    size_t length;
    t_string new;

    if (!string || !string->data)
        return (NULL);
    length = len(string);
    str = malloc(sizeof(char) * (length + 1));
    if (!str)
        return (NULL);
    i = string->start;
    while (i < string->end) {
        str[i - string->start] = string->data[i];
        i++;
    }
    str[length] = 0;
    ctor(&new, str);
    free(str);
    return (new);
}

t_string str_ncpy(t_string string, size_t size) {
    char *str;
    size_t i;
    size_t length;
    t_string new;

    if (!string || !string->data)
        return (NULL);
    i = string->start;
    length = len(string);
    if (length > size)
        length = size;
    str = malloc(sizeof(char) * (length + 1));
    if (!str)
        return (NULL);
    while (i < string->end && (i - string->start) < length) {
        str[i - string->start] = string->data[i];
        i++;
    }
    str[length] = 0;
    ctor(&new, str);
    free(str);
    return (new);
}

char *p_str_cpy(const char *string) {
    char *new;
    size_t length;
    size_t i;

    if (string == NULL)
        return (NULL);
    i = 0;
    length = p_len(string);
    new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return (NULL);
    while (i < length) {
        new[i] = string[i];
        i++;
    }
    new[length] = 0;
    return (new);
}

char *p_str_ncpy(const char *string, size_t size) {
    char *new;
    size_t i;

    if (string == NULL)
        return (NULL);
    i = 0;
    new = malloc(sizeof(char) * (size + 1));
    while (string[i] != 0 && i < size) {
        new[i] = string[i];
        i++;
    }
    new[size] = 0;
    return (new);
}
