#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str *t_string;

//  stirng.c
void        dtor(t_string *this);
void        ctor(t_string *this, char *data);
//  io.c
void        print(t_string this);
void        printe(t_string this);
void        printfd(t_string this, int fd);
void        printlist(t_string this);
//  cp.c
t_string    str_cpy(t_string this);
t_string    str_ncpy(t_string this, size_t size);
t_string    nstr_cpy(t_string this);
t_string    nstr_ncpy(t_string this, size_t size);
//  cmp.c
size_t      str_cmp(t_string one, t_string two);
size_t      pstr_cmp(t_string one, char *two);
size_t      str_ncmp(t_string one, t_string two, size_t max);
size_t      pstr_ncmp(t_string one, char *two, size_t max);
size_t      endswith(t_string this, t_string s_suffix, char *p_suffix);
//  split.c
t_string    split(t_string this, t_string delimitator);
t_string    nsplit(t_string this, char delimitator);
void        clearlist(t_string this, size_t size);
// utils.c
void        findword(t_string this, char delimitator, t_string word);
size_t      len(t_string this);

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