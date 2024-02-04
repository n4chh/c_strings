# include "libstrings.h"

size_t len(t_string this)
{
    size_t  length;

    if (this->end > this->start)
    {
        length = this->end - this->start;
        return (length);
    }
    else
        return (0);
}

void    pfindword(t_string   this, char  *delimitator, t_string   word)
{
    while (this->data[word->start + this->start] == delimitator)
        word->start++;
    word->end = word->start + this->start;
    while (word->end < this->end 
        && this->data[word->end] != delimitator)
        word->end++;
}
void    findword(t_string   this, t_string  delimitator, t_string   word)
{
    size_t  word_len;
    size_t  init_start;
    
    init_start = 0;
    word_len = len(word);
    while (str_ncmp(word, this, word_len))
    {

    }
    while (this->data[word->start + this->start])
        word->start++;
    word->end = word->start + this->start;
    while (word->end < this->end 
        && this->data[word->end] != delimitator)
        word->end++;
}

