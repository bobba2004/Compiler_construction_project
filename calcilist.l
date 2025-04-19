%{
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "calcilist.h"
#include "calcilist.tab.h"

void yyerror(char *s);
%}

%%
"int"                     { yylval.str_val = strdup(yytext); return TYPE; }
"float"                   { yylval.str_val = strdup(yytext); return TYPE; }
"char"                    { yylval.str_val = strdup(yytext); return TYPE; }
"double"                  { yylval.str_val = strdup(yytext); return TYPE; }
"if"                      { return IF; }
"else"                    { return ELSE; }
"while"                   { return WHILE; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.str_val = strdup(yytext); return ID; }
[0-9][0-9]*               { yylval.num_val = atof(yytext); return NUM; }
[0-9][0-9]*\.[0-9]+       { yylval.num_val = atof(yytext); return NUM; }
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
int main(void) {
    while (yylex() != 'q');
    return 0;
}
#endif