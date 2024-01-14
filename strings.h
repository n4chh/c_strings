#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str *t_string;
// typedef enum {
//     PRINT,
//     PRINTE,
//     PRINTFD,
//     STRCPY,
//     STRNCPY,
//     FUNC_NUM
// } t_func;
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
void        split(t_string this, char delimitator);
void        printlist(t_string this);
void        clearlist(t_string this, size_t size);
// void    getfunc_io(t_string  this);
// void    getfunc_cp(t_string  this);

struct s_str {
    size_t      start;
    size_t      end;
    char        *data;
    size_t      data_len;
    char        mask;
    t_string    *list;
    size_t      list_size;
    // void        *(*f[FUNC_NUM])(t_string this, void *extra);
    // void        (*print)(t_string   this);
    // void        (*printe)(t_string   this);
    // void        (*printfd)(t_string   this, int fd);
    // t_string    (*strcpy)(t_string  this);
    // t_string    (*strncpy)(t_string  this, int size);
};


#endif