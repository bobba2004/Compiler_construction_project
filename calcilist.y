%debug
%{
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "calcilist.h"
#include "calcilist.tab.h"

extern int yylex(void);
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yywrap() {
    return 1;
}

#define println printf("\n")
#define printlist(l) PrintList(l, 0); println

/* Function prototypes */
list *ReverseList(list *);
char *EvaluateToLiteral(list *, int);
list *ExecuteExternalCall(char *, list *);

/* Function pointer type for external calls */
typedef double (*MathFunc)(double);

/* Table of supported math functions */
struct MathFunction {
    char *name;
    MathFunc func;
} mathFunctions[] = {
    {"sin", sin},
    {"cos", cos},
    {"sqrt", sqrt},
    {"tan", tan},
    {NULL, NULL}
};

%}

%union {
    list *list_val;
    double num_val;
    char *str_val;
}

%token <num_val> NUM
%token <str_val> TYPE ID
%token IF ELSE WHILE
%token EQ NEQ LT GT LE GE AND OR

%type <list_val> PROGRAM STATEMENTS STATEMENT ASSIGN IF_STATEMENT WHILE_STATEMENT
%type <list_val> FUNCTION_CALL EXPR_LIST EXPR_TAIL EXPR TERM FACTOR LIST NUM_LIST

%%
PROGRAM     :   STATEMENTS                     { printf("Program execution complete.\n"); $$ = $1; }
            ;

STATEMENTS  :   STATEMENTS STATEMENT           { $$ = $1; }
            |   /* empty */                   { $$ = NULL; }
            ;

STATEMENT   :   EXPR '\n'                      { printlist($1); $$ = $1; }
            |   '\n'                           { $$ = NULL; }
            |   ASSIGN '\n'                    { $$ = $1; }
            |   TYPE                           { free($1); $$ = NULL; }
            |   ID                             { printf("Value of %s: ", $1); PrintList(getVarVal($1), 0); free($1); $$ = NULL; }
            |   IF_STATEMENT                   { $$ = $1; }
            |   WHILE_STATEMENT                { $$ = $1; }
            |   FUNCTION_CALL '\n'             { printlist($1); $$ = $1; }
            ;
            
ASSIGN      :   ID '=' NUM                     { list *n = NewNode(); n->value = $3; updateVar($1, n); free($1); $$ = n; }
            |   ID '=' LIST                    { list *reversed = ReverseList($3); updateVar($1, reversed); free($1); $$ = reversed; }
            |   ID '=' EXPR                    { updateVar($1, $3); free($1); $$ = $3; }
            ;

IF_STATEMENT:   IF '(' EXPR ')' '{' STATEMENTS '}' 
                                               { 
                                                   if (EvaluateCondition($3) != 0.0) {
                                                       printf("Condition evaluated to true.\n");
                                                   } else {
                                                       printf("Condition evaluated to false.\n");
                                                   }
                                                   $$ = $6;
                                               }
            |   IF '(' EXPR ')' '{' STATEMENTS '}' ELSE '{' STATEMENTS '}' 
                                               { 
                                                   if (EvaluateCondition($3) != 0.0) {
                                                       printf("If-block executed.\n");
                                                       $$ = $6;
                                                   } else {
                                                       printf("Else-block executed.\n");
                                                       $$ = $10;
                                                   }
                                               }
            ;

WHILE_STATEMENT: WHILE '(' EXPR ')' '{' STATEMENTS '}'
                                               {
                                                   printf("While loop encountered.\n");
                                                   $$ = $6;
                                               }
            ;

FUNCTION_CALL: ID '(' EXPR_LIST ')'           { $$ = ExecuteExternalCall($1, $3); free($1); }
            ;

EXPR_LIST   :   EXPR EXPR_TAIL                { $$ = $1; /* EXPR_TAIL handles chaining */ }
            |   /* empty */                   { $$ = NULL; }
            ;

EXPR_TAIL   :   ',' EXPR EXPR_TAIL            { $2->rest = $3; $$ = $2; }
            |   /* empty */                   { $$ = NULL; }
            ;
            
EXPR        :   EXPR '+' TERM                 { $$ = Add($1, $3); }
            |   EXPR '-' TERM                 { $$ = Subtract($1, $3); }
            |   TERM                          { $$ = $1; }
            |   EXPR EQ TERM                  { $$ = Compare($1, $3, 1); }
            |   EXPR NEQ TERM                 { $$ = Compare($1, $3, 2); }
            |   EXPR LT TERM                  { $$ = Compare($1, $3, 3); }
            |   EXPR GT TERM                  { $$ = Compare($1, $3, 4); }
            |   EXPR LE TERM                  { $$ = Compare($1, $3, 5); }
            |   EXPR GE TERM                  { $$ = Compare($1, $3, 6); }
            |   EXPR AND TERM                 { $$ = Compare($1, $3, 7); }
            |   EXPR OR TERM                  { $$ = Compare($1, $3, 8); }
            ;
            
TERM        :   TERM '*' FACTOR               { $$ = Multiply($1, $3); }
            |   TERM '/' FACTOR               { $$ = Divide($1, $3); }
            |   FACTOR                        { $$ = $1; }
            ;
            
FACTOR      :   '(' EXPR ')'                  { $$ = $2; }
            |   NUM                           { list *n = NewNode(); n->value = $1; $$ = n; }
            |   '[' LIST ']'                  { $$ = $2; }
            |   ID                            { $$ = getVarVal($1); free($1); }
            |   '-' FACTOR                    { $$ = Negate($2); }
            |   FUNCTION_CALL                 { $$ = $1; }
            ;
            
LIST        :   '[' NUM_LIST ']'              { $$ = $2; }
            ;
            
NUM_LIST    :   NUM_LIST NUM                  { list *n = NewNode(); n->value = $2; n->rest = $1; $$ = n; printf("NUM_LIST: Added %g\n", $2); }
            |   NUM                           { list *n = NewNode(); n->value = $1; $$ = n; printf("NUM_LIST: Started with %g\n", $1); }
            |   /* empty */                   { $$ = NULL; }
            ;
%%

/* C Code Section */

int varCount = 0;
#define MAX_VARS 150
Variable *symbolTable[MAX_VARS];

int nodecount = 0;

/* Function to reverse a list */
list *ReverseList(list *lst) {
    list *prev = NULL;
    list *current = lst;
    list *next = NULL;

    while (current) {
        next = current->rest;
        current->rest = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/* Evaluate expression to C literal */
char *EvaluateToLiteral(list *expr, int use_c_delimiters) {
    if (!expr) return strdup("0.0");

    char *result = (char *)malloc(1024 * sizeof(char));
    result[0] = '\0';

    if (!expr->rest && !expr->first) {
        /* Scalar */
        snprintf(result, 1024, "%g", expr->value);
    } else {
        /* Vector */
        list *current = expr;
        strcat(result, use_c_delimiters ? "{" : "[");
        while (current) {
            char temp[32];
            snprintf(temp, 32, "%g", current->value);
            strcat(result, temp);
            current = current->rest;
            if (current) strcat(result, use_c_delimiters ? ", " : " ");
        }
        strcat(result, use_c_delimiters ? "}" : "]");
    }

    return result;
}

/* Execute external function call */
list *ExecuteExternalCall(char *func_name, list *args) {
    /* Find function in table */
    MathFunc func = NULL;
    for (int i = 0; mathFunctions[i].name; i++) {
        if (strcmp(func_name, mathFunctions[i].name) == 0) {
            func = mathFunctions[i].func;
            break;
        }
    }

    if (!func) {
        printf("Error: Unknown function %s\n", func_name);
        list *result = NewNode();
        result->value = 0.0;
        return result;
    }

    list *result = NewNode();

    if (!args) {
        /* No arguments - invalid */
        printf("Error: Function %s requires arguments\n", func_name);
        result->value = 0.0;
        return result;
    }

    if (!args->rest && !args->first) {
        /* Single scalar argument */
        result->value = func(args->value);
    } else {
        /* Vector argument */
        list *current = args;
        list *result_current = result;
        while (current) {
            result_current->value = func(current->value);
            current = current->rest;
            if (current) {
                result_current->rest = NewNode();
                result_current = result_current->rest;
            }
        }
    }

    return result;
}

/* Modified PrintList to support C-style delimiters */
void PrintList(list *l, int use_c_delimiters) {
    if (!l) return;
    printf("%s", use_c_delimiters ? "{" : "[");
    list *current = l;
    while (current) {
        printf("%g", current->value);
        current = current->rest;
        if (current) printf("%s", use_c_delimiters ? ", " : " ");
    }
    printf("%s", use_c_delimiters ? "}" : "]");
}

int findVar(char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(symbolTable[i]->name, name) == 0)
            return i;
    }
    return -1;
}

void insertVar(char *name, list *value) {
    if (varCount >= MAX_VARS) {
        printf("Error: Variable table is full! Please retry.\n");
        exit(1);
    }
    
    if (findVar(name) != -1) {
        printf("Error: Variable '%s' is already declared! Please retry.\n", name);
        exit(1);
    }
    symbolTable[varCount] = (Variable *)malloc(sizeof(Variable));
    strcpy(symbolTable[varCount]->name, name);
    symbolTable[varCount]->value = value;
    varCount++;
}

void updateVar(char *name, list *value) {
    int index = findVar(name);
    
    if (index == -1) {
        insertVar(name, value);
        return;
    }

    symbolTable[index]->value = value;
}

list *CopyList(list *src) {
    if (!src) return NULL;

    list *head = NewNode();
    list *current = head;
    list *src_current = src;

    current->value = src_current->value;
    while (src_current->rest) {
        src_current = src_current->rest;
        current->rest = NewNode();
        current = current->rest;
        current->value = src_current->value;
    }

    return head;
}

list *getVarVal(char *name) {
    int index = findVar(name);
    
    if (index == -1) {
        list *defaultVal = NewNode();
        defaultVal->value = 0.0;
        insertVar(name, defaultVal);
        return CopyList(defaultVal);
    }
    return CopyList(symbolTable[index]->value);
}

list *NewNode(void) {
    list *temp = (list *)malloc(sizeof(list));
    if (temp) {
        nodecount++;
        temp->first = NULL;
        temp->rest = NULL;
        temp->value = 0.0;
        temp->name = (char *)malloc(100 * sizeof(char));
        if (!temp->name) {
            printf("Memory allocation failed for node name\n");
            exit(1);
        }
        temp->name[0] = '\0';
    } else {
        printf("Memory allocation failed for new node\n");
        exit(1);
    }
    return temp;
}

void FreeRecursive(list *l) {
    while (l) {
        list *next = l->rest;
        free(l->name);
        free(l);
        nodecount--;
        l = next;
    }
}

void AddAtomToList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value += num;
        current = current->rest;
    }
}

list *Add(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) return CopyList(two);
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        AddAtomToList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        AddAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value + p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void MultiplyAtomToList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value *= num;
        current = current->rest;
    }
}

list *Multiply(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) return CopyList(two);
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        printf("Multiplying list by scalar %g\n", two->value);
        MultiplyAtomToList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        printf("Multiplying list by scalar %g\n", one->value);
        MultiplyAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value * p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void SubtractAtomFromList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value -= num;
        current = current->rest;
    }
}

list *Subtract(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) {
        list *result = CopyList(two);
        MultiplyAtomToList(-1, result);
        return result;
    }
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        SubtractAtomFromList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        MultiplyAtomToList(-1, result);
        AddAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value - p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void DivideListByAtom(list *l, double num) {
    if (num == 0) {
        printf("Error: Division by zero!\n");
        exit(1);
    }
    list *current = l;
    while (current) {
        current->value /= num;
        current = current->rest;
    }
}

list *Divide(list *one, list *two) {
    if (!one) return NULL;
    if (!two) {
        printf("Error: Division by NULL!\n");
        exit(1);
    }
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        if (two->value == 0) {
            printf("Error: Division by zero!\n");
            exit(1);
        }
        result = CopyList(one);
        DivideListByAtom(result, two->value);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        list *current = result;
        while (current) {
            if (current->value == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            current->value = one->value / current->value;
            current = current->rest;
        }
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            if (p2->value == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            current->value = p1->value / p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

list *Negate(list *l) {
    if (!l) return NULL;
    
    list *result = CopyList(l);
    MultiplyAtomToList(-1, result);
    
    return result;
}

list *Compare(list *one, list *two, int operation) {
    if (!(one && two)) return NULL;
    
    list *result = NewNode();
    
    if (one->rest == NULL && !one->first && two->rest == NULL && !two->first) {
        switch (operation) {
            case 1: // EQ
                result->value = (one->value == two->value) ? 1.0 : 0.0;
                break;
            case 2: // NEQ
                result->value = (one->value != two->value) ? 1.0 : 0.0;
                break;
            case 3: // LT
                result->value = (one->value < two->value) ? 1.0 : 0.0;
                break;
            case 4: // GT
                result->value = (one->value > two->value) ? 1.0 : 0.0;
                break;
            case 5: // LE
                result->value = (one->value <= two->value) ? 1.0 : 0.0;
                break;
            case 6: // GE
                result->value = (one->value >= two->value) ? 1.0 : 0.0;
                break;
            case 7: // AND
                result->value = (one->value && two->value) ? 1.0 : 0.0;
                break;
            case 8: // OR
                result->value = (one->value || two->value) ? 1.0 : 0.0;
                break;
            default:
                result->value = 0.0;
        }
    } else {
        result->value = 0.0;
    }
    
    return result;
}

double EvaluateCondition(list *expr) {
    if (!expr) return 0.0;
    
    if (expr->rest || expr->first) {
        return EvaluateCondition(expr->rest ? expr->rest : expr->first);
    } else {
        return expr->value;
    }
}

int main(int argc, char *argv[]) {
    printf("WizuAll Vector Calculator\n");
    printf("Start Typing: \n");
    yyparse();
    return 0;
}