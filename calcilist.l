%{
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "calcilist.h"
#include "calcilist.tab.h"

void yyerror(char*);

%}

%%
"int"                     { return TYPE; }
"float"                   { return TYPE; }
"char"                    { return TYPE; }
"double"                  { return TYPE; }
"if"                      { return IF; }
"else"                    { return ELSE; }
"while"                   { return WHILE; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval = NewNode(); strcpy(yylval->name, yytext); return ID; }
[0-9][0-9]*               { yylval = NewNode(); yylval->value = atof(yytext); return NUM; }
[0-9][0-9]*\.[0-9]+       { yylval = NewNode(); yylval->value = atof(yytext); return NUM; }
\n                        { return *yytext; }
"=="                      { return EQ; }
"!="                      { return NEQ; }
"<="                      { return LE; }
">="                      { return GE; }
"<"                       { return LT; }
">"                       { return GT; }
"&&"                      { return AND; }
"||"                      { return OR; }
"{"                       { return *yytext; }
"}"                       { return *yytext; }
[ \t]*                    { /* Do nothing, drop them. */ }
.                         { return *yytext; }
%%

#ifdef STANDALONE_LEXER
int main(void)
{
    while(yylex()!='q');
}
#endif