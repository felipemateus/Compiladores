compilador.o: lex.yy.c
	g++ lex.yy.c -lfl -o compilador.o

lex.yy.c: scanner.lex
	lex scanner.lex

clean:
	rm  *.o
