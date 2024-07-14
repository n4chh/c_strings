#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_str *t_string;

//  stirng.c
void dtor(t_string *string);
void ctor(t_string *string, const char *data);
//  io.c
void print(t_string string);
void printe(t_string string);
void printfd(t_string string, int fd);
void printnl(t_string string);
//  cp.c
t_string str_cpy(t_string string);
t_string str_ncpy(t_string string, size_t size);
char *p_str_cpy(const char *string);
char *p_str_ncpy(const char *string, size_t size);
//  cmp.c
long int str_cmp(t_string one, t_string two);
long int str_ncmp(t_string one, t_string two, size_t max);
long int p_str_cmp(t_string one, const char *two);
long int p_str_ncmp(t_string one, const char *two, size_t max);
long int endswith(t_string string, t_string s_suffix, char *p_suffix);
//	join.c
t_string str_joinfront(t_string string, t_string preffix);
t_string p_str_joinfront(t_string string, const char *preffix);
t_string str_joinback(t_string string, t_string suffix);
t_string p_str_joinback(t_string string, const char *suffix);
//  split.c
t_string *split(t_string string, t_string delimitator);
void printlist(t_string *string, t_string separator);
t_string *nsplit(t_string string, size_t splits, size_t *position);
//	p_split.c
t_string *p_split(t_string string, const char *delimitator);
void p_printlist(t_string *string, const char *separator);
char **strlstocharls(t_string *list);
//	nsplit.c
t_string *nsplit(t_string string, size_t splits, size_t *position);
t_string *pos_split(t_string string, size_t position[][2]);
t_string lstostr(t_string *list);
//	sub.c
t_string substr_rm(t_string string, t_string substr);
t_string p_substr_rm(t_string string, const char *substr);
long substr(t_string string, t_string substr);
long p_substr(t_string string, const char *substr);
//	rm.c
void clearlist(t_string **string);
void p_strrmsuffix(t_string string, const char *delimitator);
t_string p_strtrim(t_string string, const char *delimitator);
t_string str_rmpos(t_string string, size_t start, size_t end);
// utils.c
void findword(t_string string, t_string delimitator);
void p_findword(t_string string, const char *delimitator);
size_t len(t_string string);
size_t p_len(const char *str);
// find.c
long int findchar(t_string string, const char c);
long int p_findchar(const char *string, const char c);
// get_set.c
char get(t_string string, size_t index);
char set(t_string string, size_t index, const char value);

struct s_str {
    size_t start;
    size_t end;
    char *data;
    size_t data_len;
};
#endif
