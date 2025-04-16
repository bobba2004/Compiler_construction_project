YACC := bison -d
LEX := flex
CFLAGS := -Wall -lm -DYYERROR_VERBOSE
CC := gcc

all: Makefile wizuall

wizuall: lex.yy.c calcilist.tab.c calcilist.h calcilist.tab.h Makefile
	$(CC) lex.yy.c calcilist.tab.c -o wizuall $(CFLAGS)

lex.yy.c: calcilist.l
	$(LEX) calcilist.l

calcilist.tab.c calcilist.tab.h: calcilist.y
	$(YACC) calcilist.y

clean:
	rm -f lex.yy.c calcilist.tab.c calcilist.tab.h wizuall

.PHONY: all clean