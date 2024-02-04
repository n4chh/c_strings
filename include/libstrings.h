#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str	*t_string;

//  stirng.c
void					dtor(t_string *this);
void					ctor(t_string *this, char *data);
//  io.c
void					print(t_string this);
void					printe(t_string this);
void					printfd(t_string this, int fd);
void					printlist(t_string this);
void					printnl(t_string this);
//  cp.c
t_string				str_cpy(t_string this);
t_string				str_ncpy(t_string this, size_t size);
t_string				nstr_cpy(t_string this);
t_string				nstr_ncpy(t_string this, size_t size);
//  cmp.c
long int				str_cmp(t_string one, t_string two);
long int				p_str_cmp(t_string one, char *two);
long int				str_ncmp(t_string one, t_string two, size_t max);
long int				p_str_ncmp(t_string one, char *two, size_t max);
long int				endswith(t_string this, t_string s_suffix,
							char *p_suffix);
//  split.c
t_string				split(t_string this, t_string delimitator);
t_string				nsplit(t_string this, t_string delimitator);
void					clearlist(t_string this, size_t size);
// psplit.c
t_string				p_split(t_string this, char *delimitator);
t_string				p_nsplit(t_string this, char *delimitator);
// utils.c
void					findword(t_string this, t_string delimitator);
void					p_findword(t_string this, char *delimitator);
size_t					len(t_string this);
size_t					p_len(char	*str);

struct					s_str
{
	size_t				start;
	size_t				end;
	char				*data;
	size_t				data_len;
	char				isson;
	t_string			*list;
	size_t				list_size;
};
#endif