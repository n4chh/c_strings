#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>

typedef struct s_str {
    int     start;
    int     end;
    char    *data;
    int     data_len;
    void    (*destructor)(t_string *);
} t_string;

void    destructor(t_string *this);
#endif