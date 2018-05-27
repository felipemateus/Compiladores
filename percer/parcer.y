%{
		#include <stdio.h>
		#include <stdlib.h>
		#include "exp.h"

		int yylex();
		int yyparse();
		void yyerror(const char* s);

		int countLines = 1;

		using namespace std;

%}

%token NUM
%token INT IF ELSE WHILE RETURN VOID
%token KEY ID SYB ERROR
/*  tokens de operadores com mais de character:
  	LE  	"<="
		GE  	">="
		EQUAL "=="
		DIF   "!="*/
%token LE GE EQUAL DIF
%left '+' '-'
%left '*' '/'

%start program

%%

program :							 	declaration_list												{printf("Program [\n");}
											;
declaration_list:  		 	declaration declaration_list						{printf("declaration_list1 ;\n");}
											| declaration																					{printf("declaration_list2 ;\n");}
											;
declaration:				 	 	var_declaration													{printf("declaration1 ;\n");}
											|	fun_declaration													{printf("declaration2 ;\n");}
											;

/* ---------------------------------------------------*/
var_declaration : 			type_specifier ID	';'										{printf("var_declaration1 ;\n");}
											| type_specifier ID '[' NUM ']' ';'				{printf("var_declaration2 ;\n");}
											;
type_specifier 	: 			INT																			{printf("INT tipo\n");}
											| VOID
											;

/* ---------------------------------------------------*/

fun_declaration: 				type_specifier ID '('params ')' compound_stmt		{printf("fUNC \n");}
											;
params: 								param_list
											| VOID
											;
param_list: 						param_list ',' param
											| param
											;
param:									type_specifier ID
											| type_specifier ID '['']'
											;
/* ---------------------------------------------------*/

compound_stmt:				 '{' local_declarations statement_list '}'				{printf("fUNC \n");}
											;

/* ---------------------------------------------------*/

local_declarations : 		local_declarations var_declaration
											| %empty
											;
statement_list : 				statement_list statement
											| %empty
											;
/* ---------------------------------------------------*/

statement :							expression_stmt
											| compound_stmt
											| selection_stmt
              				| iteration_stmt
											| return_stmt
											;
expression_stmt :				expression ';'
											| ';'
											;
selection_stmt:				 	IF '(' expression ')' statement
                  		| IF '(' expression ')' statement ELSE statement

iteration_stmt:	  			WHILE '(' expression ')' statement
											;

return_stmt :				 		RETURN ';'
											| RETURN expression ';'
											;

expression :				 		var '=' expression
											| simple_expression
											;
var :				 						ID
											| ID '[' expression ']'
											;

simple_expression :			additive_expression relop additive_expression
                      | additive_expression
											;
relop :							 		LE
											| '<'
											| '>'
											| GE
											| EQUAL
											| DIF
											;

additive_expression :		additive_expression addop term
											| term
											;
addop :				 					'+'
											| '-'
											;
term :				 					term mulop factor
											| factor
											;
mulop :									'*'
											| '/'
											;

factor :							 '(' expression ')'
											| var
											| call
											| NUM						{printf("NUM \n");}
											;

call :				 					ID '(' args ')'
											;
args :				 					arg-list
											| %empty
											;
arg-list :					 		arg-list ',' expression
											| expression
											;







%%

int main(){
	number_node NUMBER(2);
	NUMBER.print();
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	fprintf(stderr, "Linha %d\n", countLines);
	exit(1);
}
