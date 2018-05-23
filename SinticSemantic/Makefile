y.tab.c:syntatic.y
	bison -d -y syntatic.y

lex.yy.c: scanner.lex
	lex scanner.lex

compilador.o: lex.yy.c
	g++ -c y.tab.c lex.yy.c
	g++ -g y.tab.c lex.yy.c syntatic.c -o compilador.o



clean:
	rm  *.o
