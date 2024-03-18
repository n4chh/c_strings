#include "libstrings.h"

void	clearlist(t_string **string)
{
	size_t	i;

	i = 0;
	while ((*string)[i])
		dtor(&(*string)[i++]);
	free(*string);
	*string = NULL;
}

void	p_strrmsuffix(t_string string, const char *delimitator)
{
	size_t	start;	
	size_t	del_len;

	del_len = p_len(delimitator);	
	if (del_len > string->end)
		return ;
	start = string->start;
	string->start = string->end - del_len;
	while ( string->start - del_len < string->end
		&& p_str_ncmp(string, delimitator, del_len) == -1)
	{
		string->end -= del_len;
		string->start -= del_len;	
	}
	string->start = start;
}

t_string	str_rmpos(t_string	string, size_t start, size_t end)
{
	size_t		str_start;
	size_t		str_end;
	t_string	left_half;
	t_string	cleared_str;
	
	str_start = string->start;
	str_end = string->end;
	string->end = start;
	left_half = str_cpy(string);
	if (!left_half)
		return (NULL);
	string->end = str_end;
	printnl(left_half);
	string->start = end + 1;
	printnl(string);
	cleared_str = str_joinback(left_half, string);
	dtor(&left_half);
	string->start = str_start;
	printnl(string);
	return (cleared_str);
}

t_string	p_strtrim(t_string string, const char *delimitator)
{
	t_string	trimed;
	size_t		start;
	size_t		end;

	start = string->start;
	end = string->end;
	p_findword(string, delimitator);
	p_strrmsuffix(string, delimitator);
	trimed = str_cpy(string);
	string->start = start;
	string->end = end ;
	return (trimed);
}