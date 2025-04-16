#ifndef CALCILIST_H
#define CALCILIST_H

#define YYSTYPE list *

typedef struct _list
{
    struct _list *first, *rest;
    double value;
    char *name;
} list;

extern char *yytext;

list *NewNode(void);
void PrintList(list *l);

#endif