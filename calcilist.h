#ifndef CALCILIST_H
#define CALCILIST_H

typedef struct _list {
    struct _list *first, *rest;
    double value;
    char *name;
} list;

typedef struct Variable {
    char name[150];
    list *value;
} Variable;

extern char *yytext;

// Function prototypes
list *NewNode(void);
void FreeRecursive(list *l);
void PrintList(list *l, int use_c_delimiters);
list *CopyList(list *src);
void AddAtomToList(double num, list *l);
void MultiplyAtomToList(double num, list *l);
void SubtractAtomFromList(double num, list *l);
void DivideListByAtom(list *l, double num);
list *Add(list *one, list *two);
list *Subtract(list *one, list *two);
list *Multiply(list *one, list *two);
list *Divide(list *one, list *two);
list *Negate(list *l);
list *Compare(list *one, list *two, int operation);
double EvaluateCondition(list *expr);
int findVar(char *name);
void insertVar(char *name, list *value);
void updateVar(char *name, list *value);
list *getVarVal(char *name);
char *EvaluateToLiteral(list *expr, int use_c_delimiters);
list *ExecuteExternalCall(char *func_name, list *args);

#endif