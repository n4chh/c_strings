# include "strings.h"

// static void getfunc(t_string this)
// {
//     if (!this)
//         return (void)"";
//     getfunc_io(this);
//     getfunc_cp(this);
// }

void    dtor(t_string *this)
{
    if (!this || !(*this)) 
        return (void)"";
    if (!(*this)->mask && (*this)->data)
        free((*this)->data);
    if ((*this)->list)
        clearlist(*this, 0);
    (*this)->data = NULL;
    free(*this);
    *this = NULL;
}

void    ctor(t_string *this, char *data)
{
    if (!this)
        return (void)"";
    *this = malloc(sizeof(struct s_str));
    if (*this)
    {
        (*this)->start = 0;
        (*this)->end = 0;
        (*this)->data_len = 0;
        (*this)->mask = 0;
        (*this)->list = NULL;
        (*this)->list_size = 0;
        if (data)
        {
            while (data[(*this)->end])
                (*this)->end++;
            (*this)->data = malloc(sizeof(char) * (*this)->end);
            while ((*this)->data && data[(*this)->data_len])
            {
                (*this)->data[(*this)->data_len] = data[(*this)->data_len];
                (*this)->data_len++;
}
        }
    }
}


