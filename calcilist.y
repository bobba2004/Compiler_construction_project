%debug
%{
extern int yylex(void);
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "calcilist.h"
#include "calcilist.tab.h"

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
    return;
}

int yywrap()
{
    return 1;
}

#define printob printf("[")
#define printcb printf("]")
#define println printf("\n")
#define printlist(l) PrintList(l); println

typedef struct Variable {
    char name[150];  // Variable name
    list* value;     // Variable value
} Variable;

int varCount = 0;
#define MAX_VARS 150
Variable *symbolTable[MAX_VARS];

/* Forward declarations of functions */
void AddAtomToList(double num, list *l);
void MultiplyAtomToList(double num, list *l);
void SubtractAtomFromList(double num, list *l);
void DivideListByAtom(list *l, double num);
list* Add(list *one, list *two);
list* Subtract(list *one, list *two);
list* Multiply(list *one, list *two);
list* Divide(list *one, list *two);
list* Negate(list *l);
list* CopyList(list *src);
list* Compare(list *one, list *two, int operation);
double EvaluateCondition(list *expr);

int findVar(char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(symbolTable[i]->name, name) == 0)
            return i;  // Return index if found
    }
    return -1;  // Not found
}

void insertVar(char *name, list* value) {
    if (varCount >= MAX_VARS) {
        printf("Error: Variable table is full! Please retry.\n");
        exit(1);
    }
    
    // Check if variable already exists
    if (findVar(name) != -1) {
        printf("Error: Variable '%s' is already declared! Please retry.\n", name);
        exit(1);
    }
    symbolTable[varCount] = (Variable*)malloc(sizeof(Variable));
    strcpy(symbolTable[varCount]->name, name);
    symbolTable[varCount]->value = value;
    varCount++;
}

void updateVar(char *name, list* value) {
    int index = findVar(name);
    
    if (index == -1) {
        insertVar(name, value);
        return;
    }

    symbolTable[index]->value = value;
}

list* CopyList(list *src) {
    if (!src) return NULL;

    list *copy = NewNode();
    copy->value = src->value;
    if (src->name) {
        strcpy(copy->name, src->name);
    }
    copy->first = CopyList(src->first);  // Deep copy
    copy->rest = CopyList(src->rest);    // Deep copy

    return copy;
}

list* getVarVal(char *name) {
    int index = findVar(name);
    
    if (index == -1) {
        // Variable not found, create with default value 0
        list* defaultVal = NewNode();
        defaultVal->value = 0.0;
        insertVar(name, defaultVal);
        return CopyList(defaultVal);
    }
    return CopyList(symbolTable[index]->value);
}

void PrintList(list *l) {
    if(l) {
        if(l->first) {
            printob;
            PrintList(l->first);
            PrintList(l->rest);
            printcb;
        }
        else printf("%g ", l->value);
    }
}

int nodecount = 0;
list *NewNode(void) {
    list *temp = (list*)malloc(sizeof(list));
    if(temp) {
        nodecount++;
        temp->first = NULL;
        temp->rest = NULL;
        temp->value = M_E;
        temp->name = (char*)malloc(100 * sizeof(char));
        if(!temp->name) {
            printf("Memory allocation failed for node name\n");
            exit(1);
        }
        temp->name[0] = '\0';  // Initialize to empty string
    }
    else {
        printf("Memory allocation failed for new node\n");
        exit(1);
    }
    return temp;
}

void FreeRecursive(list *l) {
    if(l) {
        FreeRecursive(l->first);
        FreeRecursive(l->rest);
        free(l->name);
        free(l);
        nodecount--;
    }
}

/* Arithmetic Operations */

// Addition
void AddAtomToList(double num, list *l) {
    if(l) {
        if(l->first) {
            AddAtomToList(num, l->first);
            AddAtomToList(num, l->rest);
        }
        else l->value += num;
    }
}

list *Add(list *one, list *two) {
    if(!(one || two)) return NULL;
    if(one && !two) return CopyList(one);
    if(!one && two) return CopyList(two);
    
    list *result = NewNode();
    
    if(one->first) {
        if(two->first) {
            result->first = Add(one->first, two->first);
            result->rest = Add(one->rest, two->rest);
        }
        else {
            result = CopyList(one);
            AddAtomToList(two->value, result);
        }
    }
    else {
        if(two->first) {
            result = CopyList(two);
            AddAtomToList(one->value, result);
        }
        else {
            result->value = one->value + two->value;
        }
    }
    
    return result;
}

// Multiplication
void MultiplyAtomToList(double num, list *l) {
    if(l) {
        if(l->first) {
            MultiplyAtomToList(num, l->first);
            MultiplyAtomToList(num, l->rest);
        }
        else l->value *= num;
    }
}

list *Multiply(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) return CopyList(two);

    list *result = NewNode();
    
    if (one->first) {
        if (two->first) {
            result->first = Multiply(one->first, two->first);
            result->rest = Multiply(one->rest, two->rest);
        } else {
            result = CopyList(one);
            MultiplyAtomToList(two->value, result);
        }
    } else {
        if (two->first) {
            result = CopyList(two);
            MultiplyAtomToList(one->value, result);
        } else {
            result->value = one->value * two->value;
        }
    }
    
    return result;
}

// Subtraction
void SubtractAtomFromList(double num, list *l) {
    if (l) {
        if (l->first) {
            SubtractAtomFromList(num, l->first);
            SubtractAtomFromList(num, l->rest);
        } else {
            l->value -= num;
        }
    }
}

list *Subtract(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) {
        list *result = CopyList(two);
        // Negate all values in the list
        if (result->first) {
            SubtractAtomFromList(0, result); // Reset to 0
            MultiplyAtomToList(-1, result);  // Multiply by -1
        } else {
            result->value = -result->value;
        }
        return result;
    }
    
    list *result = NewNode();
    
    if (one->first) {
        if (two->first) {
            result->first = Subtract(one->first, two->first);
            result->rest = Subtract(one->rest, two->rest);
        } else {
            result = CopyList(one);
            SubtractAtomFromList(two->value, result);
        }
    } else {
        if (two->first) {
            result = CopyList(two);
            MultiplyAtomToList(-1, result);  // Negate the second list
            AddAtomToList(one->value, result);  // Add the first value
        } else {
            result->value = one->value - two->value;
        }
    }
    
    return result;
}

// Division
void DivideListByAtom(list *l, double num) {
    if (l) {
        if (l->first) {
            DivideListByAtom(l->first, num);
            DivideListByAtom(l->rest, num);
        } else {
            if (num == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            l->value /= num;
        }
    }
}

void DivideListByList(list *result, list *dividend, list *divisor) {
    if (dividend && divisor) {
        if (dividend->first && divisor->first) {
            if (result->first == NULL) {
                result->first = NewNode();
            }
            DivideListByList(result->first, dividend->first, divisor->first);
            
            if (dividend->rest && divisor->rest) {
                if (result->rest == NULL) {
                    result->rest = NewNode();
                }
                DivideListByList(result->rest, dividend->rest, divisor->rest);
            }
        } else if (!dividend->first && !divisor->first) {
            if (divisor->value == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            result->value = dividend->value / divisor->value;
        }
    }
}

list *Divide(list *one, list *two) {
    if (!one) return NULL;
    if (!two) {
        printf("Error: Division by NULL!\n");
        exit(1);
    }
    
    // Check for division by zero
    if (!two->first && two->value == 0) {
        printf("Error: Division by zero!\n");
        exit(1);
    }
    
    list *result = NewNode();
    
    if (one->first) {
        if (two->first) {
            // Element-wise division for both lists
            result->first = NewNode();
            DivideListByList(result, one, two);
        } else {
            // Divide list by scalar
            result = CopyList(one);
            DivideListByAtom(result, two->value);
        }
    } else {
        if (two->first) {
            // Divide scalar by list (element-wise)
            result = CopyList(two);
            // First invert each element
            if (result->first) {
                list *temp = result->first;
                while (temp) {
                    if (!temp->first && temp->value != 0) {
                        temp->value = 1.0 / temp->value;
                    }
                    temp = temp->rest;
                }
            } else if (result->value != 0) {
                result->value = 1.0 / result->value;
            }
            // Then multiply by scalar
            MultiplyAtomToList(one->value, result);
        } else {
            // Simple scalar division
            result->value = one->value / two->value;
        }
    }
    
    return result;
}

// Unary Minus (Negation)
list *Negate(list *l) {
    if (!l) return NULL;
    
    list *result = CopyList(l);
    
    if (result->first) {
        // Recursively negate all elements
        list *temp = result;
        while (temp) {
            if (temp->first) {
                temp->first = Negate(temp->first);
            }
            temp = temp->rest;
        }
    } else {
        result->value = -result->value;
    }
    
    return result;
}

// Comparison Operations
list *Compare(list *one, list *two, int operation) {
    if (!(one && two)) return NULL;
    
    list *result = NewNode();
    
    // For now, only handle scalar comparison
    if (!one->first && !two->first) {
        switch(operation) {
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
        // For lists, we'd need to implement vector comparison
        // For now, just return 0
        result->value = 0.0;
    }
    
    return result;
}

// Evaluate a condition to determine if it's "true" (non-zero)
double EvaluateCondition(list *expr) {
    if (!expr) return 0.0;
    
    if (expr->first) {
        // For lists, evaluate the first element
        return EvaluateCondition(expr->first);
    } else {
        // For scalars, just return the value
        return expr->value;
    }
}

list *lst; /* for debugging. temp. */

%}

%token NUM TYPE ID IF ELSE WHILE
%token EQ NEQ LT GT LE GE AND OR

%%
PROGRAM     :   STATEMENTS                     { printf("Program execution complete.\n"); }
            ;

STATEMENTS  :   STATEMENTS STATEMENT
            |   /* empty */
            ;

STATEMENT   :   EXPR '\n'                      { printlist($1); }
            |   '\n'
            |   ASSIGN '\n'
            |   TYPE
            |   ID                              { printf("Value of %s: ", $1->name); PrintList(getVarVal($1->name)); printf("\n"); }
            |   IF_STATEMENT
            |   WHILE_STATEMENT
            |   FUNCTION_CALL '\n'              { printlist($1); }
            ;
            
ASSIGN      :   ID '=' NUM                      { updateVar($1->name, $3); }
            |   ID '=' LIST                     { updateVar($1->name, $3); }
            |   ID '=' EXPR                     { updateVar($1->name, $3); }
            ;

IF_STATEMENT:   IF '(' EXPR ')' '{' STATEMENTS '}' 
                                            { 
                                                if (EvaluateCondition($3) != 0.0) {
                                                    printf("Condition evaluated to true.\n");
                                                } else {
                                                    printf("Condition evaluated to false.\n");
                                                }
                                            }
            |   IF '(' EXPR ')' '{' STATEMENTS '}' ELSE '{' STATEMENTS '}' 
                                            { 
                                                if (EvaluateCondition($3) != 0.0) {
                                                    printf("If-block executed.\n");
                                                } else {
                                                    printf("Else-block executed.\n");
                                                }
                                            }
            ;

WHILE_STATEMENT: WHILE '(' EXPR ')' '{' STATEMENTS '}'
                                            {
                                                printf("While loop encountered.\n");
                                                // In a proper implementation, we would execute the statements
                                                // while the condition is true
                                            }
            ;

FUNCTION_CALL: ID '(' EXPR_LIST ')'           { printf("Function %s called with arguments.\n", $1->name); $$ = $3; }
            ;

EXPR_LIST   :   EXPR_LIST ',' EXPR            { $$ = Add($1, $3); } 
            |   EXPR                          { $$ = $1; }
            |   /* empty */                   { $$ = NULL; }
            ;
            
EXPR        :   EXPR '+' TERM                   { $$ = Add($1, $3); }
            |   EXPR '-' TERM                   { $$ = Subtract($1, $3); }
            |   TERM                            { $$ = $1; }
            |   EXPR EQ TERM                    { $$ = Compare($1, $3, 1); }
            |   EXPR NEQ TERM                   { $$ = Compare($1, $3, 2); }
            |   EXPR LT TERM                    { $$ = Compare($1, $3, 3); }
            |   EXPR GT TERM                    { $$ = Compare($1, $3, 4); }
            |   EXPR LE TERM                    { $$ = Compare($1, $3, 5); }
            |   EXPR GE TERM                    { $$ = Compare($1, $3, 6); }
            |   EXPR AND TERM                   { $$ = Compare($1, $3, 7); }
            |   EXPR OR TERM                    { $$ = Compare($1, $3, 8); }
            ;
            
TERM        :   TERM '*' FACTOR                 { $$ = Multiply($1, $3); }
            |   TERM '/' FACTOR                 { $$ = Divide($1, $3); }
            |   FACTOR                          { $$ = $1; }
            ;
            
FACTOR      :   '(' EXPR ')'                    { $$ = $2; }
            |   NUM                             { $$ = $1; }
            |   '[' LIST ']'                    { $$ = $2; }
            |   ID                              { $$ = getVarVal($1->name); }
            |   '-' FACTOR                      { $$ = Negate($2); }
            |   FUNCTION_CALL                   { $$ = $1; }
            ;
            
LIST        :   NUM EXTEND                      { $$ = NewNode(); $$->first = $1; $$->rest = $2; }
            |   '[' LIST ']' EXTEND             { $$ = NewNode(); $$->first = $2; $$->rest = $4; }
            ;
            
EXTEND      :   LIST                            { $$ = $1; }
            |                                   { $$ = NULL; }
            ;
%%

int main(int argc, char *argv[])
{
    printf("WizuAll Vector Calculator\n");
    printf("Start Typing: \n");
    yyparse();
    return 0;
}