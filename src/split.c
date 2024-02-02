# include "strings.h"

static int wordcount(t_string   this, char  delimitator)
{
    int     words;
    size_t  i;

    words = 0;
    i = this->start;
    while (i < this->end)
    {
        if (this->data[i] != delimitator
            && (i == this->end - 1
            || this->data[i + 1] == delimitator))
            words++;
        i++;
    }
    return (words);
}

void    findword(t_string   this, char  delimitator, t_string   word)
{
    while (this->data[word->start + this->start] == delimitator)
        word->start++;
    word->end = word->start + this->start;
    while (word->end < this->end 
        && this->data[word->end] != delimitator)
        word->end++;
}

void    clearlist(t_string this, size_t size)
{
    if (!this->list)
        return (void)"";
    if (size == 0)
        while (this->list_size--)
            dtor(&this->list[this->list_size]);
    else
        while (size--)
            dtor(&this->list[size]);
    
}

t_string    split(t_string this, char delimitator)
{
    size_t      w;
    t_string    str;

    w = 0;
    if (this->list)
        clearlist(this, 0);
    this->list_size = wordcount(this, delimitator);
    this->list = malloc(sizeof(t_string) * this->list_size);
    if (!this->list)
        this->list_size = 0;
    str = str_cpy(this);
    if (!str)
        return (NULL); 
    while (w++ < this->list_size)
    {
        findword(this, delimitator, str);
        this->list[w - 1] = nstr_cpy(str);
        if (this->list[w - 1] == NULL)
            return (clearlist(this, w - 1), NULL);
        str->start = str->end;
    }
    dtor(&str);
    return (this);
}

t_string    nsplit(t_string this, char delimitator)
{
    t_string    newlist;

    if (this->list)
        clearlist(this, 0);
    newlist = nstr_cpy(this);
    if (!newlist)
        return (NULL);
    if (split(newlist, delimitator))
        return (newlist);
    else
    {
        dtor(&newlist);
        return (NULL);
    }
}
