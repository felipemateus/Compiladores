all: parcer

parcer.tab.c parcer.tab.h: parcer.y
	bison -d parcer.y

lex.yy.c: scanner.lex
	flex scanner.lex

parcer:lex.yy.c parcer.tab.c parcer.tab.h class/node.cpp class/node.h
		g++ -o parcer parcer.tab.c lex.yy.c class/node.cpp -lfl

clean:
	rm parcer parcer.tab.c parcer.tab.h lex.yy.c
