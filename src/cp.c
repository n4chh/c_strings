#include "strings.h"

t_string str_cpy(t_string this)
{
    t_string    new;

    if (!this)
        return NULL;
    ctor(&new, NULL);
    if (new)
    {
        new->mask = 1;
        new->data = this->data;
        new->start = this->start;
        new->end = this->end;
        new->data_len = this->data_len;
    }
    return(new);
}

t_string str_ncpy(t_string this, size_t  size)
{
    t_string    new;

    if (!this)
        return NULL;
    ctor(&new, NULL);
    if (new)
    {
        new->mask = 1;
        new->start = this->start;
        new->data = this->data;
        if (size < this->end)
            new->end = size;
        else
            new->end = this->end;
        new->data_len = this->data_len;
    }
    return(new);
}

t_string nstr_cpy(t_string this)
{
    char        str[this->end + 1 - this->start];
    size_t      i;
    t_string    new;

    i = this->start;
    while (i < this->end)
    {
        str[i - this->start] = this->data[i];
        i++;
    }
    str[this->end - this->start] = 0;
    ctor(&new, str);
    return new;
}

t_string nstr_ncpy(t_string this, size_t size)
{
    char        str[size + 1];
    size_t      i;
    t_string    new;

    i = this->start;
    while (i < this->end && (i - this->start) < size)
    {
        str[i - this->start] = this->data[i];
        i++;
    }
    str[i - this->start] = 0;
    ctor(&new, str);
    return new;
}

// void    getfunc_cp(t_string this)
// {
//     this->strcpy = strcpy;
//     this->strncpy = strncpy;
// }