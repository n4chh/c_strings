#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str *t_string;

void        dtor(t_string *this);
void        ctor(t_string *this, char *data);
void        print(t_string this);
void        printe(t_string this);
void        printfd(t_string this, int fd);
t_string    str_cpy(t_string this);
t_string    str_ncpy(t_string this, size_t size);
t_string    nstr_cpy(t_string this);
t_string    nstr_ncpy(t_string this, size_t size);
void        findword(t_string this, char delimitator, t_string word);
t_string    split(t_string this, char delimitator);
t_string    nsplit(t_string this, char delimitator);
void        printlist(t_string this);
void        clearlist(t_string this, size_t size);
struct s_str {
    size_t      start;
    size_t      end;
    char        *data;
    size_t      data_len;
    char        mask;
    t_string    *list;
    size_t      list_size;
};
#endif