#include "libstrings.h"

t_string    substr_rm(t_string  this, t_string substr)
{

}
t_string    p_substr_rm(t_string  this, char *substr)
{
    t_string    str;
    size_t      i;
    size_t      sublength;
    t_string    new;

    i = 0;
    sublength = p_len(substr);
    str = this;
    while (this->end > str->start && p_str_ncmp(str, substr, sublength))
        str->start++;

}