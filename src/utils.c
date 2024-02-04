#include "libstrings.h"

size_t	len(t_string this)
{
	size_t	length;

	if (this->end > this->start)
	{
		length = this->end - this->start;
		return (length);
	}
	else
		return (0);
}

void	pfindword(t_string this, char *delimitator)
{
	size_t	new_start;
	size_t	del_len;

	del_len = 0;
	while (delimitator[del_len])
		del_len++;
	while (pstr_ncmp(this, delimitator, del_len) == -1)
		this->start += del_len;
	new_start = this->start;
	while (this->start < this->end && pstr_ncmp(this, delimitator,
			del_len) >= 0)
		this->start++;
	this->end = this->start;
	this->start = new_start;
}

void	findword(t_string this, t_string delimitator)
{
	size_t	del_len;
	size_t	new_start;

	del_len = len(delimitator);
	while (str_ncmp(this, delimitator, del_len) == -1)
		this->start += del_len;
	new_start = this->start;
	while (this->start < this->end && str_ncmp(this, delimitator, del_len) >= 0)
		this->start++;
	this->end = this->start;
	this->start = new_start;
}
